import requests as request
import os
from time import time
from urllib.parse import unquote

# COLORS
def r(text): return "\033[91m{}\033[00m" .format(text)
def g(text): return "\033[92m{}\033[00m" .format(text)
def y(text): return "\033[93m{}\033[00m" .format(text)
def lp(text): return "\033[94m{}\033[00m" .format(text)
def p(text): return "\033[95m{}\033[00m" .format(text)
def c(text): return "\033[96m{}\033[00m" .format(text)
def lg(text): return "\033[97m{}\033[00m" .format(text)
def b(text): return "\033[98m{}\033[00m" .format(text)

# THIS IS WHERE YOUR DOWNLOADED FILE WAS SAVED, YOU CAN EDIT THIS
PATH = '/sdcard/download/fbdl/'

if os.path.exists(PATH) is False:
 os.mkdir(PATH)

logo = f"""
______________________________________________________
                                            
           This is an Facebook Downloader
         Free to use and a Open Source Project.
      
  [{r('#')}] Author: {g('Ryan Naisu')}
  [{r('#')}] Github: {g('https://github.com/ryannaisu')}
  [{r('#')}] Facebook: {g('https://www.facebook.com/ryan.naisu.7')}
  [{r('#')}] Team: {g('No Team im Solo')}
  [{r('#')}] Made with: {g('Python')}
                                            
------------------------------------------------------
            \\   ^__^
             \\  (oo)\\_______
                (__)\\       )\\/\\
                    ||----w |
                    ||     ||
                                     
"""

def getData(url):
 html = request.get(url).text
 if 'video_redirect' in html:
  url = html.split('<a href="/video_redirect/?src=')[1].split('" target="_blank">')[0]
  return unquote(url).replace(';', '&')
 else:
  exit(f"[{r('!')}] Video not Found")
 
def download(url):
 content = request.get(url)
 size = round(int(content.headers.get('Content-Length')) / 1024)
 filename = str(round(time())) + '.mp4'
 print(f"[{g('#')}] Video Size: {size}KB")
 with open(PATH + filename, 'wb') as file:
  for data in content.iter_content(chunk_size=1024):
   file.write(data)
 print(f"[{g('#')}] Download Success")
 
if __name__ == '__main__':
 print(logo)
 url = input(f"[{c('?')}] Enter Video URL: ")
 data = getData(url)
 download(data)
