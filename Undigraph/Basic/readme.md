# 中山大学导游程序
**利用无向图的数据结构实现一个路径规划导览程序**
<br>

1.程序流程
流程图如下：

```
1.将来访客人的询问类型分为两类：询问地点信息，和询问地点间最短路径
->2.对于询问地点信息，可用map容器进行各地点信息的存储，易于查找
->3.对于询问地点间最短路径，利用Dijsktra算法计算出指定起点最短路径，并返回对应路径
```



2.设计工具
编程语言：c++
IDE：visual studio pycharm(拓展部分)

