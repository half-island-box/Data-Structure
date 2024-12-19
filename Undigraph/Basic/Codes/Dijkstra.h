

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
    int num_node; //��������
    int num_edges; //���������
    map<string, int> cast; //����ӳ��Ϊ���
    map<int, string> nodes; //���ӳ��Ϊ����
    map<string, string> message; //������Ӧ������Ϣ
    int** edges; //�ڽӾ���

    void DFS(int node, int visit[]);
    void BFS(int node, int visit[]);
    void dfs(int node, int visit[], int end, vector<string>& q);
public:
    Undigraph(int n, int m, Edge e[]);
    void Depth_Print(); //��ȱ���
    void Broad_Print(); //��ȱ���
    string Dijkstra(string begin, string end, int is); //�������·��
    string Dijkstra_pass(string begin, string end, queue<string> pass); //��;��������·��
    void All_route(string begin, string end); //�о����������·��
    string show_message(string tar); //չʾ�ص���Ϣ
    ~Undigraph();

};


#endif //UNDIGRAPH_H
