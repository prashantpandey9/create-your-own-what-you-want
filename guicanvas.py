from tkinter import *
win=Tk()
win.geometry("750x250")
def style():
 label.configure(font=('impact',25,'italic'),fg='white',bg='black')
 button.configure(text='close',command=lambda:win.destroy())
# create canvas
canvas=Canvas(win,width=600,height=200,bg='bisque')
canvas.pack(fill=BOTH,expand=True)
# create rectangle
canvas.create_rectangle(500,200,300,400,fill='red')
#create Label inside of canvas
label=Label(canvas,text="welcome students",font=20)
label.pack(pady=14)
# create button insdie of canvas
button=Button(canvas,text='click',command=style)
button.pack(pady=20)
win.mainloop()
