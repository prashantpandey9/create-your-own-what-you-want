from pynput.keyboard import Key, Controller
import time
import os
keyboard = Controller()
while True:
    n = input("[__] Enter Time After Which Typing Should Start: ")
    try:
    	n = int(n)
    	break
    except Exceptiona as e:
    	print("[!] Please Enter Right Input: Integet!")
    	continue
for i in range(n):
    print("[*] This app will start autotyping in",n - i,"second(s).",end='\r')
    i-=1
    time.sleep(1)
# Open text from text.txt file

lst = os.listdir()
# Check for file is there or not...
if "data.txt" not in lst:
    print("[!] 'data.txt' not found! Creating file...")
    with open("data.txt", "w") as file_w:
        file_w.write("Hello World!\nWelcome To AutoTyper")
        print("[*] Done!")

print("[*] Autotyping has started. Please close this window to stop autotyping!")

with open('data.txt', 'r') as file_r:
    typeString = file_r.read()
    
for char in typeString:
    if char == '\n':
        keyboard.type("\n")    
    else:
        keyboard.type(char)    
    time.sleep(0.03)