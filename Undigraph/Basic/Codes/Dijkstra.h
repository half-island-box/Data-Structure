

#ifndef UNDIGRAPH_H
#define UNDIGRAPH_H



#include<iostream>
#include<queue>
#include<stack>
#include<string>
#include<map>

using namespace std;

class Edge {
public:
    int x, y, w;
    Edge() {}
    Edge(int _x, int _y, int _w) {
        x = _x; y = _y; w = _w;
    }
};


class Undigraph {
private:
    int num_node; //顶点数量
    int num_edges; //无向边数量
    map<string, int> cast; //地名映射为序号
    map<int, string> nodes; //序号映射为地名
    map<string, string> message; //定名对应介绍信息
    int** edges; //邻接矩阵

    void DFS(int node, int visit[]);
    void BFS(int node, int visit[]);
    void dfs(int node, int visit[], int end, vector<string>& q);
public:
    Undigraph(int n, int m, Edge e[]);
    void Depth_Print(); //深度遍历
    void Broad_Print(); //广度遍历
    string Dijkstra(string begin, string end, int is); //单点最短路径
    string Dijkstra_pass(string begin, string end, queue<string> pass); //带途径点的最短路径
    void All_route(string begin, string end); //列举两点间所有路径
    string show_message(string tar); //展示地点信息
    ~Undigraph();

};


#endif //UNDIGRAPH_H
