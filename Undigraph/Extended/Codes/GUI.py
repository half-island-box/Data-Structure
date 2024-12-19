import tkinter as tk
from tkinter import messagebox

from pyexpat.errors import messages

import Undigraph as g

# 创建主应用类
class App:
    def __init__(self, master):
        self.master = master
        self.master.title("中山大学校园导览")

        # 创建主界面
        self.main_frame = tk.Frame(self.master)
        self.main_frame.pack()

        # 添加图片标签
        self.photo = tk.PhotoImage(file='picture.png')
        show = tk.Label(self.main_frame, image=self.photo)  # 将标签改为放在 main_frame 内
        show.pack(pady=5)

        # 创建按钮以进入界面1
        self.button1 = tk.Button(self.main_frame, text="路线查询", command=self.show_frame1)
        self.button1.pack(pady=10)

        # 创建界面1的内容
        self.frame1 = tk.Frame(self.master)
        self.photo1 = tk.PhotoImage(file='map.png')
        # 创建标签并显示图片
        label = tk.Label(self.frame1, image=self.photo1)
        label.pack(pady=5)  # 添加一些垂直间距
        # 创建框架以安置第一组引导文本和输入框
        frame_1 = tk.Frame(self.frame1)
        frame_1.pack(pady=5)  # 添加一些垂直间距

        guide_label_1 = tk.Label(frame_1, text="请输入起点:")
        guide_label_1.pack(side=tk.LEFT)  # 左侧对齐引导文本

        entry1 = tk.Entry(frame_1, width=30)  # 设置宽度为 30
        entry1.pack(side=tk.LEFT, padx=10)  # 左侧对齐输入框，添加水平间距


        # 创建框架以安置第二组引导文本和输入框
        frame_2 = tk.Frame(self.frame1)
        frame_2.pack(pady=5)  # 添加一些垂直间距

        guide_label_2 = tk.Label(frame_2, text="请输入终点:")
        guide_label_2.pack(side=tk.LEFT)  # 左侧对齐引导文本

        entry2 = tk.Entry(frame_2, width=30)  # 设置宽度为 30
        entry2.pack(side=tk.LEFT, padx=10)  #

        self.button_frame1=tk.Frame(self.frame1)
        self.button_frame1.pack(pady=5)

        # 返回主界面的按钮
        back_button1 = tk.Button(self.button_frame1, text="返回主界面", command=self.show_main_frame)
        back_button1.pack(side=tk.LEFT, padx=(0,10))



        edges = [
            g.Edge(1, 2, 2),
            g.Edge(2, 3, 1),
            g.Edge(2, 4, 1),
            g.Edge(4, 5, 2),
            g.Edge(3, 5, 3),
            g.Edge(6, 7, 4),
            g.Edge(7, 8, 4),
            g.Edge(4, 7, 2),
            g.Edge(5, 8, 5),
            g.Edge(7, 9, 10),
            g.Edge(8, 10, 8),
            g.Edge(5,10,10)
        ]
        graph = g.Undigraph(11, 12, edges)


        # 创建标签显示响应内容
        self.response_label = tk.Label(root, text="")  # 初始文本为空
        self.response_label.pack(pady=10)  # 添加一些垂直间距

        # 创建响应函数
        def respond_to_input1():
            begin = entry1.get()  # 获取输入框内容
            end = entry2.get()  # 获取输入框内容
            response_text1=graph.dijkstra(begin, end, 0)
            messagebox.showinfo("查询结果",response_text1)

        # 创建响应函数
        def respond_to_input3():
            begin = entry1.get()  # 获取输入框内容
            end = entry2.get()  # 获取输入框内容
            response_text3=graph.all_route(begin, end)
            messagebox.showinfo("查询结果",response_text3)



        # 创建提交按钮来调用响应函数
        button1 = tk.Button(self.button_frame1, text="最短路线查询", command=respond_to_input1)
        button1.pack(side=tk.LEFT)  # 添加一些垂直间距

        button3=tk.Button(self.button_frame1, text="列举所有路径", command=respond_to_input3)
        button3.pack(side=tk.LEFT)



        # 创建按钮以进入界面2
        self.button2 = tk.Button(self.main_frame, text="地点信息查询", command=self.show_frame2)
        self.button2.pack(pady=10)

        # 创建界面2的内容
        self.frame2 = tk.Frame(self.master)
        self.photo2 = tk.PhotoImage(file='map.png')
        # 创建标签并显示图片
        label = tk.Label(self.frame2, image=self.photo2)
        label.pack(pady=5)  # 添加一些垂直间距
        # 创建框架以安置第一组引导文本和输入框
        frame_2 = tk.Frame(self.frame2)
        frame_2.pack(pady=5)  # 添加一些垂直间距

        guide_label_2 = tk.Label(frame_2, text="请输入查询地点:")
        guide_label_2.pack(side=tk.LEFT)  # 左侧对齐引导文本

        entry3 = tk.Entry(frame_2, width=30)  # 设置宽度为 30
        entry3.pack(side=tk.LEFT, padx=10)  # 左侧对齐输入框，添加水平间距

        # 创建响应函数
        def respond_to_input2():
            name=entry3.get()
            response_text2=graph.show_messages(name)
            messagebox.showinfo("查询结果",response_text2)



        # 创建提交按钮来调用响应函数
        button2 = tk.Button(self.frame2, text="提交", command=respond_to_input2)
        button2.pack(pady=10)  # 添加一些垂直间距

        # 返回主界面的按钮
        back_button2 = tk.Button(self.frame2, text="返回主界面", command=self.show_main_frame)
        back_button2.pack(padx=(0,10))



    def show_frame1(self):
        """显示界面1并隐藏主界面"""
        self.main_frame.pack_forget()  # 隐藏主界面
        self.frame1.pack()  # 显示界面1

    def show_frame2(self):
        self.main_frame.pack_forget()  # 隐藏主界面
        self.frame2.pack()  # 显示界面2

    def show_main_frame(self):
        """显示主界面并隐藏其他界面"""

        self.frame1.pack_forget()  # 隐藏界面1
        self.frame2.pack_forget()  # 隐藏界面2
        self.main_frame.pack()  # 显示主界面
        self.response_label.config(text="")




# 启动主循环
root=tk.Tk()
app=App(root)
root.mainloop()