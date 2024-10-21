import tkinter as tk
import operate as op


class GUI:
    def __init__(self, master):
        self.master=master
        self.master.title("计算器")

        self.expression=""

        self.entry=tk.Entry(master, width=16, font=('Arial', 24), borderwidth=5, relief=tk.RAISED)
        self.entry.grid(row=0, column=0, columnspan=4)

        self.create_buttons()

    def create_buttons(self):
        buttons=[
            ('7', 1, 0), ('8', 1, 1), ('9', 1, 2), ('/', 1, 3),
            ('4', 2, 0), ('5', 2, 1), ('6', 2, 2), ('*', 2, 3),
            ('1', 3, 0), ('2', 3, 1), ('3', 3, 2), ('-', 3, 3),
            ('0', 4, 0), ('b', 4, 1), ('^', 4, 2), ('+', 4, 3),
             ('(',5, 0), (')', 5, 1),
        ]

        button = tk.Button(self.master, text='#', width=11, height=2,  font=('Arial', 18),
                           command=lambda t='#': self.click(t))
        button.grid(row=5, column=2, columnspan=2)


        for (text, row, col) in buttons:
            button=tk.Button(self.master, text=text, width=5, height=2, font=('Arial', 18),
                             command=lambda t=text:self.click(t))
            button.grid(row=row, column=col)

    def click(self, char):

        if char=='b':
            self.expression = self.expression[:-1]
            self.entry.delete(0, tk.END)
            self.entry.insert(0, self.expression)
        elif char=='#':
            self.expression+='#'
            self.expression=op.evaluate_expression(self.expression) #计算结果
            self.entry.delete(0, tk.END)
            self.entry.insert(0, self.expression)
            self.expression=""
        else:
            self.expression+=char
            self.entry.delete(0, tk.END)
            self.entry.insert(0, self.expression)



if __name__=="__main__":
    root=tk.Tk()
    calculator=GUI(root)
    root.mainloop()