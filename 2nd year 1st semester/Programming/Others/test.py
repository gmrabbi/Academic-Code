
from tkinter import *
import matplotlib.pyplot as plt
from tkinter import messagebox
root = Tk()
#root.resizable(True,True)
root.title("Equation Solver and Visualization")
root.configure(bg="pink")

def Clear_fn():
    x11.delete(0, END)
    y11.delete(0, END)
    c11.delete(0, END)
    x22.delete(0, END)
    y22.delete(0, END)
    c22.delete(0, END)

def On_press():

    x1 = int(x11.get())
    y1 = int(y11.get())
    c1 = int(c11.get())

    x2 = int(x22.get())
    y2 = int(y22.get())
    c2 = int(c22.get())

    f = []
    e = []

    for i in range(100):
        f.append(i)
        x_1 = (c1 - (y1 * i)) / x1
        e.append(x_1)
    # plt.plot(e, f, color="red")

    q = []
    p = []

    for i in range(100):
        q.append(i)
        x_2 = (c2 - (y2 * i)) / x2
        p.append(x_2)
    # plt.plot(p, q, color="blue")
    
    if(((x1 * y2) - (x2 * y1)) ):
        X = (((-1 * c2) * y1) - ((c1 * -1) * y2)) / ((x1 * y2) - (x2 * y1))
        Y = (((-1*c1) * x2) - ((c2 * -1) * x1)) / ((x1 * y2) - (x2 * y1))
        
        plt.plot(e, f, color="red")
        plt.plot(p, q, color="blue")

        plt.plot(X, Y, marker='o', markerfacecolor='yellow', markersize=12)

        xx = round(X, 2)
        yy = round(Y, 2)

        plt.plot(x1, y1, label='First line')
        plt.plot(x2, y2, label='Second line')

        score_lbl3.config(
            text=f"Intersecting point of two lines : {xx,yy}", bg="pink")

        plt.axis([0, 2 * xx, 0, 2 * yy])
        plt.text(xx + 0.2, yy + 0.2, f'({xx},{yy})')

        plt.style.use('bmh')
        #plt.legend(loc=1)
        plt.legend()

        plt.xlabel('x-axis')
        plt.ylabel('y-axis')
        plt.grid(True)
        plt.show()
    else:
        messagebox.showerror("0/0 Error", "Zero division Error")


Label(root, text="Equation 1", font="ar 15 bold",
      bg="pink").grid(row=2, column=1, padx=10, pady=20)

a_lbl = Label(root, text=" ", bg="pink")
x11 = Entry(root)
b_lbl = Label(root, text=" X1 ", bg="pink")
y11 = Entry(root)
c_lbl = Label(root, text=" +  Y1  = ", bg="pink")
c11 = Entry(root)


a_lbl.grid(row=3, column=1)
x11.grid(row=3, column=2)
b_lbl.grid(row=3, column=3)
y11.grid(row=3, column=4)
c_lbl.grid(row=3, column=5)
c11.grid(row=3, column=6)


Label(root, text="Equation 2", font="ar 15 bold",
      bg="pink").grid(row=5, column=1, padx=10, pady=20)

a_lbl2 = Label(root, text=" ", bg="pink")
x22 = Entry(root)
b_lbl2 = Label(root, text="X2 ", bg="pink")
y22 = Entry(root)
c_lbl2 = Label(root, text=" +  Y2  =", bg="pink")
c22 = Entry(root)

score_lbl3 = Label(root, text="", font=("bold", 20))


btn2 = Button(root, text='SOLVE', width=30, bg='brown',
              fg='white', command=On_press).grid(row=20, column=2)

clr_btn = Button(root, text='CLEAR', width=30, bg='brown',
              fg='white', command=Clear_fn).grid(row=20, column=5)

score_lbl3.grid(row=22, column=4)


a_lbl2.grid(row=6, column=1, pady=10, padx=10)
x22.grid(row=6, column=2, pady=10, padx=10)
b_lbl2.grid(row=6, column=3, pady=10, padx=10)
y22.grid(row=6, column=4, pady=10, padx=10)
c_lbl2.grid(row=6, column=5, pady=10, padx=10)
c22.grid(row=6, column=6, pady=10, padx=10)


root.mainloop()
