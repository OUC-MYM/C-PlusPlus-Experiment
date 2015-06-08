from tkinter import *
import tkinter.messagebox as messagebox

class Application(Frame):
    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.pack()
        self.createWidgets()

    def createWidgets(self):
        self.nameInput = Entry(self)
        self.nameInput.pack()
        self.alertButton = Button(self, text='N！', command=self.hello)
        self.alertButton.pack()

    def hello(self):
        name = self.nameInput.get()
        n = int(name)
        sum = 1
        while n>0:
            sum=sum+n
            n=n-1
        messagebox.showinfo('Message', '%d!= %d' %(int(name),sum))

app = Application()
# 设置窗口标题:
app.master.title('计算n的阶乘')
# 主消息循环:
app.mainloop()

