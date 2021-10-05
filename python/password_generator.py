import string
import random

chars = ""
strings = [string.digits + string.ascii_letters + string.punctuation]
for x in strings:
    chars += x
separator = ""
flag = 1

while flag:
    length_pass = int(input("Enter length of password:"))
    if length_pass < 7:
        print("Password should be atleast 7 characters long")
        flag = 1
    else :
        flag = 0
print(f"Your password: {separator.join(random.sample(chars, length_pass))}")