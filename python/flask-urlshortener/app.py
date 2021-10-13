import requests
from flask import *
from flask_mysqldb import MySQL
import MySQLdb.cursors
import random , string
import os


app = Flask(__name__)

app.config['MYSQL_HOST'] = "<db_host>"
app.config['MYSQL_USER'] ="<db_user>"
app.config['MYSQL_PASSWORD'] = "<db_password>"
app.config['MYSQL_DB'] = "<db_name>"

mysql = MySQL(app)

def random_code():
    characters = string.ascii_letters + string.digits
    code = ''.join(random.choice(characters) for i in range(8))
    return code

def get_query(code):
        cursor = mysql.connection.cursor(MySQLdb.cursors.DictCursor)
        cursor.execute("SELECT * FROM urlshortener WHERE code = %s",[code])
        short_code = cursor.fetchone()
        return (short_code)

def redirect_to_url(code):
        cursor = mysql.connection.cursor(MySQLdb.cursors.DictCursor)
        cursor.execute("SELECT * FROM urlshortener WHERE code = %s",[code])
        short_code = cursor.fetchone()
        view_count = int(short_code["view_count"]) + 1
        increase_view_count(view_count,code)
        return (short_code)

def insert_query(longurl , code):
    ip_address = request.remote_addr
    cursor = mysql.connection.cursor(MySQLdb.cursors.DictCursor)
    cursor.execute('INSERT INTO `urlshortener` (`longurl`,`code`,`added_by`,`view_count`) VALUES ( %s, %s, %s,0)', (longurl, code,ip_address))
    mysql.connection.commit()

def increase_view_count(view_count,code):
    cursor = mysql.connection.cursor(MySQLdb.cursors.DictCursor)
    cursor.execute("UPDATE `urlshortener` SET `view_count` = %s WHERE `code` = %s",(view_count,code))
    mysql.connection.commit()

@app.route('/')
def index():
    return "URL Shortner is Up and Running"

@app.route("/add", methods=["GET"])
def generate_code():
    if request.method == "POST" or request.method=="GET":
        longurl = request.args.get("url")
        try:
            res = requests.get(longurl)
            if res.status_code == 200:
                code = random_code()
                insert_query(longurl,code)
                return f"Inserted Successfully at {code}"
            else:
                return "Invalid URL"
        except:
            return "Invalid URL"

@app.route("/details/<code>")
def get_longurl_info(code):
    query = get_query(code)
    return jsonify(query)

@app.route("/<code>")
def get_longurl(code):
    query = redirect_to_url(code)
    return redirect(query["longurl"])

if __name__ == "__main__":
    app.run(debug=True)