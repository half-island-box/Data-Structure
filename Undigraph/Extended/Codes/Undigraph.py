from collections import deque
import sys
import heapq


class Edge:
    def __init__(self, x=0, y=0, w=0):
        self.x = x  # 起点
        self.y = y  # 终点
        self.w = w  # 权重


class Undigraph:
    def __init__(self, n, m, edges):
        self.num_node = n  # 节点数量
        self.num_edges = m  # 边数量
        self.edges = [[0] * (n + 1) for _ in range(n + 1)]  # 初始化邻接矩阵

        # 初始化边
        for e in edges:
            self.edges[e.x][e.y] = e.w
            self.edges[e.y][e.x] = e.w

            # 初始化节点名称
        self.nodes = {
            1: "生命科学楼",
            2: "校训",
            3: "黑石屋",
            4: "怀士堂",
            5: "陈寅恪故居",
            6: "孙中山纪念馆",
            7: "孙中山铜像",
            8: "松涛园",
            9: "北门石牌",
            10: "广寒宫",
        }

        self.messeges={
            1:"位于中山大学南门西侧，隶属于中山大徐生命科学学院。",
            2:"中山大学校徽和校训，游客必打卡。",
            3:"芝加哥的伊沙贝·布勒斯顿（黑石）夫人出资为担任过岭南学堂教务长和岭南大学校长的钟荣光博士（岭南大学首位华人校长）修建的寓所。是中大红楼的代表。",
            4: "中山大学标志性建筑，孙孙中山先生在此发表名句“立志做大事，不可做大官。",
            5:"原名麻金墨屋一号，史学大师陈寅恪故居。",
            6:"孙中山纪念馆创建于1953年，在孙中山诞辰八十七周年、中山大学建校二十九周年校庆之际，“孙中山先生纪念室”落成开幕，是新中国成立后中国大陆建立的第一家孙中山纪念机构。",
            7:"孙中山纪念铜像是在孙中山先生逝世后，孙中山先生的日本友人梅屋庄吉先生在1932年赠送给中国的4具塑像。",
            8:"位于中山大学南校园东北部，是校园内占地最大，最豪华的食堂。",
            9:"位于广州中大海珠校区（即南校区）北门，门额刻有“国立中山大学”六个大字， 系2001年参照原有的国立中山牌坊复制而成。中山大学牌坊一直以来都是广州中山大学的标志。",
            10:"由中国妇女和新泽西州岭南之友共同捐建，1933年落成，现为博雅学院宿舍。"
        }

        # 初始化节点索引
        self.cast = {value: key for key, value in self.nodes.items()}

    def DFS(self, node, visit):
        print(node, end=" ")
        visit[node] = 1
        for i in range(1, self.num_node + 1):
            if self.edges[node][i] != 0 and visit[i] == 0:
                self.DFS(i, visit)

    def depth_print(self):
        visit = [0] * (self.num_node + 1)
        for i in range(1, self.num_node + 1):
            if visit[i] == 0:
                self.DFS(i, visit)
        print()

    def bfs(self, node, visit):
        q = deque([node])
        visit[node] = 1
        while q:
            current = q.popleft()
            print(current, end=" ")
            for i in range(1, self.num_node + 1):
                if not visit[i] and self.edges[current][i] != 0:
                    q.append(i)
                    visit[i] = 1

    def broad_print(self):
        visit = [0] * (self.num_node + 1)
        for i in range(1, self.num_node + 1):
            if visit[i] == 0:
                self.bfs(i, visit)
        print()

    def dijkstra(self, begin, end, kind):
        if begin or end not in self.cast:
            return "起点或终点不在图中"

        node = self.cast[begin]  # 起点
        tar = self.cast[end]  # 终点
        dist = [float('inf')] * (self.num_node + 1)  # 路径长度
        path = [-1] * (self.num_node + 1)  # 前驱节点
        s = [0] * (self.num_node + 1)  # 已找到最短路径的节点
        dist[node] = 0

        for _ in range(self.num_node):
            min_idx = -1
            for i in range(1, self.num_node + 1):
                if s[i] == 0 and (min_idx == -1 or dist[i] < dist[min_idx]):
                    min_idx = i  # 找到最小距离的节点

            if min_idx == -1:
                break  # 如果无可达节点，跳出循环

            newnode = min_idx
            s[newnode] = 1  # 找到最短路径的节点

            for i in range(1, self.num_node + 1):
                if self.edges[newnode][i] != 0 and dist[i] > dist[newnode] + self.edges[newnode][i]:
                    dist[i] = dist[newnode] + self.edges[newnode][i]
                    path[i] = newnode

                    # 输出最短路径
        st = []
        x = tar
        while x != -1:
            st.append(x)
            x = path[x]

        st.pop()
        str=""
        if  kind== 0:
            str+=self.nodes[node]

        while st:
            str+="->"
            str+=self.nodes[st.pop()]

        return str

    def show_messages(self, name):
        if name not in self.cast:
            return "起点或终点不在图中"
        index=self.cast[name]
        return self.messeges[index]

    def dijkstra_pass(self, begin, end, pass_nodes):
        if begin or end not in self.cast:
            return "起点或终点不在图中"
        route = ""
        route += self.dijkstra(begin, pass_nodes[0], 0)  # Assume dijkstra() returns a string
        while len(pass_nodes) > 1:
            x = pass_nodes[0]
            pass_nodes.pop(0)  # Simulate queue behavior
            y = pass_nodes[0]
            route += self.dijkstra(x, y, 1)
        route += self.dijkstra(pass_nodes[0], end, 1)
        return route


    def all_route(self, begin, end):
        if begin or end not in self.cast:
            return "起点或终点不在图中"
        q = []
        visit = [0] * self.num_node  # 初始化访问数组
        all_paths = []  # 用于存储所有路径
        self.dfs( self.cast[begin], visit, self.cast[end], q, all_paths)

        # 将所有路径用换行符拼接成一个字符串并返回
        return "\n".join(all_paths)  # 每条路径用换行分割

    def dfs(self, node, visit, end, q, all_paths):
        q.append(self.nodes[node])  # 添加当前节点到路径中
        if node == end:
            # 将当前路径转换为字符串并添加到 all_paths
            all_paths.append("->".join(q))
        visit[node] = 1  # 标记当前节点为已访问
        for i in range(self.num_node):  # 遍历所有邻接节点
            if visit[i] == 0 and self.edges[node][i] != 0:
                self.dfs(i, visit, end, q, all_paths)
        visit[node] = 0  # 回溯时标记当前节点为未访问
        q.pop()  # 移除当前节点，准备下一条路径


    # 示例用法




if __name__ == "__main__":
    edges = [
         Edge(1, 2, 2),
        Edge(2, 3, 1),
        Edge(2, 4, 1),
        Edge(4, 5, 2),
         Edge(3, 5, 3),
        Edge(6, 7, 4),
        Edge(7, 8, 4),
        Edge(4, 7, 2),
         Edge(5, 8, 5),
        Edge(7, 9, 10),
        Edge(8, 10, 8),
        Edge(5,10,10)
    ]
    graph = Undigraph(10, 3, edges)
    graph.depth_print()
    graph.broad_print()
    begin=" "
    end=" "
    begin=input("请输入起点：")
    end=input("请输入终点：")
    print(graph.dijkstra(begin, end, 0))
    print(graph.show_messages("松涛园"))

