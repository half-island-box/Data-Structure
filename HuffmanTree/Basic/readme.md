# 数据压缩
**利用赫夫曼树实现一个完整的编/译码系统**
<br>

1.程序流程
流程图如下：

```
1.对data_freq.txt字符频数进行统计
->2.根据统计的频数构造赫夫曼树，形成各字符对应的编码，存储在hfm_tree中
->3.运用hfm_tree对data.source.txt的文本进行编码，形成由0、1构成的字符串，存储在data_encoded
->4.运用hfm_tree对data_encoded的01串进行解码，形成文本，存储在data_decoded。
```

2.设计工具
编程语言：c++
IDE：clion

3.运行说明
可执行文件以及各个txt文件在目录Tests下，以此保证代码从可以正常读写各个txt文件。
运行CMakeLists.txt构建项目即可运行
