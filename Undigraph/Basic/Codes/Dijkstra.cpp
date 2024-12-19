
#include"Dijkstra.h"

Undigraph::Undigraph(int n, int m, Edge e[]) {
    this->num_node = n;
    this->num_edges = m;

    this->edges = new int* [n + 1];
    for (int i = 0; i < n + 1; i++) {
        this->edges[i] = new int [n + 1] {};
    }

    for (int i = 0; i < m; i++) {

        edges[e[i].x][e[i].y] = e[i].w;
        edges[e[i].y][e[i].x] = e[i].w;
    }

    nodes[1] = "������ѧ¥";
    nodes[2] = "Уѵ";
    nodes[3] = "��ʯ��";
    nodes[4] = "��ʿ��";
    nodes[5] = "����㡹ʾ�"; 
    nodes[6] = "����ɽ�����";
    nodes[7] = "����ɽͭ��";
    nodes[8] = "����԰";
    nodes[9] = "����ʯ��";
    nodes[10] = "�㺮��";

    cast["������ѧ¥"] = 1;
    cast["Уѵ"] = 2;
    cast["��ʯ��"] = 3;
    cast["��ʿ��"] = 4;
    cast["����㡹ʾ�"] = 5;
    cast["����ɽ�����"] = 6;
    cast["����ɽͭ��"] = 7;
    cast["����԰"] = 8;
    cast["����ʯ��"] = 9;
    cast["�㺮��"] = 10;


    message["������ѧ¥"] = "λ����ɽ��ѧ�������࣬��������ɽ����������ѧѧԺ��";
    message["Уѵ"] = "��ɽ��ѧУ�պ�Уѵ���οͱش򿨡�";
    message["��ʯ��"] = "֥�Ӹ����ɳ��������˹�٣���ʯ�����˳���Ϊ���ι�����ѧ�ý��񳤺����ϴ�ѧУ�������ٹⲩʿ�����ϴ�ѧ��λ����У�����޽���Ԣ�������д��¥�Ĵ���";
    message["��ʿ��"] = "��ɽ��ѧ��־�Խ�����������ɽ�����ڴ˷������䡰��־�����£���������١�";
    message["����㡹ʾ�"] = "ԭ�����ī��һ�ţ�ʷѧ��ʦ����㡹ʾӡ�";
    message["����ɽ�����"] = "����ɽ����ݴ�����1953�꣬������ɽ������ʮ�����ꡢ��ɽ��ѧ��У��ʮ������У��֮�ʣ�������ɽ���������ҡ���ɿ�Ļ�������й��������й���½�����ĵ�һ������ɽ���������";
    message["����ɽͭ��"] = "����ɽ����ͭ����������ɽ��������������ɽ�������ձ�����÷��ׯ��������1932�����͸��й���4������";
    message["����԰"] = "λ����ɽ��ѧ��У԰����������У԰��ռ������������ʳ�á�";
    message["����ʯ��"] = "λ�ڹ����д���У��������У�������ţ��Ŷ���С�������ɽ��ѧ���������֣� ϵ2001�����ԭ�еĹ�����ɽ�Ʒ����ƶ��ɡ���ɽ��ѧ�Ʒ�һֱ�������ǹ�����ɽ��ѧ�ı�־��";
    message["�㺮��"] = "���й���Ů��������������֮�ѹ�ͬ�轨��1933����ɣ���Ϊ����ѧԺ���ᡣ";



}

void Undigraph::DFS(int node, int visit[]) {
    cout << node << " ";
    visit[node] = 1;
    for (int i = 1; i <= num_node; i++) {
        if (this->edges[node][i] == 1 && visit[i] == 0) { //�Ըý��ĸ����ڽӵ㿼��
            DFS(i, visit);
        }
    }
}

//�������
void Undigraph::Depth_Print() {
    //int visit[num_node + 1] = {};
    int* visit = new int [num_node + 1] {};
    for (int i = 1; i <= num_node; i++) { //���ǲ�����ͨͼ�Ŀ����ԣ���Ҫ�Ը���������
        if (!visit[i]) {
            DFS(i, visit);
        }
    }
    cout << endl;
    delete[] visit;
}

void Undigraph::BFS(int node, int visit[]) {
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        cout << q.front() << " ";
        visit[q.front()] = 1;
        for (int i = 1; i <= num_node; i++) { //�����ͷ�����зǱ����ڽӵ�
            if (!visit[i] && edges[q.front()][i] == 1) q.push(i);
        }
        q.pop();
    }
}

//�������
void Undigraph::Broad_Print() {
   // int visit[num_node + 1] = {};
    int* visit = new int [num_node + 1] {};
    for (int i = 1; i <= num_node; i++) {
        if (!visit[i]) {
            BFS(i, visit);
        }
    }
    cout << endl;
    delete[] visit;
}

string Undigraph::Dijkstra(string begin, string end, int is) {
    if (begin == end) {
        return "�����յ㲻�����غ�";
    }
    if (cast.find(begin) == cast.end()) return "����������Ч" ;
    int node = cast[begin];
    
    if (cast.find(end) == cast.end()) return "������յ���Ч";
    int tar = cast[end];

    int* dist = new int [num_node + 1] {}; //��¼·������
    int* path = new int [num_node + 1] {};//��¼���·���ϵ�ǰ��
    int* s = new int [num_node + 1] {};//��¼�Ѿ��ҵ����·���Ľ��
    fill(dist, dist + num_node + 1, INT_MAX); //�������int�������������Ϊ��ʼ��
    dist[node] = 0;
    fill(path, path + num_node + 1, -1);
    s[node] = 1;
    int cnt = 1;
    int newnode = node; //��¼ÿһ�ֵ����·������
    int min;
    while (cnt < num_node) {
        for (int i = 1; i <= num_node; i++) {
            if (s[i] == 0) {
                min = i;
                break;
            }

        }
        for (int i = 1; i <= num_node; i++) {
            if (edges[newnode][i] != 0 && dist[i] > dist[newnode] + edges[newnode][i] && s[i] == 0 && i != newnode) {
                //�����·���ڵ�+���·�����㵽�ö������<����ԭ·������->����·��
                dist[i] = dist[newnode] + edges[newnode][i];
                path[i] = newnode;
                // if(dist[i]<dist[min]) min=i;
            }

        }

        //ѡ�����������·���ĵ�
        for (int i = 1; i <= num_node; i++) {
            if (s[i] == 0 && dist[i] < dist[min]) min = i;
        }

        newnode = min;
        s[newnode] = 1; //�ýڵ��ҵ������·��
        cnt++;
    }


    stack<int> st;
    st.push(tar);
    int x = path[tar];
    while (x != node) {
        st.push(x);
        x = path[x];
    }

    string route = "";
    if (is == 0) route += nodes[node]; //is�����ж�·���Ƿ���Ҫ�������(������;����ʱ��ĵ���)
    while (!st.empty()) {
        route += "->";
        route += nodes[st.top()];
        st.pop();
    }
    delete[] dist;
    delete[] path;
    delete[] s;
    return route;

}

//����;��������·��
string Undigraph::Dijkstra_pass(string begin, string end, queue<string> pass) {
    string route = "";
    route += Dijkstra(begin, pass.front(), 0);
    while(pass.size()>1 ){
        string x = pass.front();
        pass.pop();
        string y = pass.front();
        route += Dijkstra(x, y, 1);
    }
    route += Dijkstra(pass.front(), end, 1);
    return route;
}




void Undigraph::All_route(string begin, string end) {
    if (begin == end) {
        cout<< "�����յ㲻�����غ�"<<endl;
        return;
    }
    if (cast.find(begin) == cast.end()) {
        cout<< "����������Ч"<<endl;
        return;
    }


    if (cast.find(end) == cast.end()) {
        cout<< "������յ���Ч";
        return;
    }
    cout << "����;�����·�����£�" << endl;
    vector<string> q;
    vector<int> visit(this->num_node, 0); // ʹ�� vector �Զ������ڴ�  
    dfs(cast[begin], visit.data(), cast[end], q); // ���� visit ��ָ��  
}

void Undigraph::dfs(int node, int visit[], int end, vector<string>& q) {
    q.push_back(nodes[node]);
    if (node == end) {
        for (size_t i = 0; i < q.size(); i++) {
            cout << q[i];
            if (i != q.size() - 1) cout << "->";
            else cout << endl;
        }
        q.pop_back(); // ����ʱҪ�Ƴ����һ���ڵ�  
        return; // �ҵ�·���󷵻�  
    }

    visit[node] = 1;
    for (int i = 1; i <= num_node; i++) { // �� 0 ��ʼ����  
        if (visit[i] == 0 && edges[node][i] != 0) {
            dfs(i, visit, end, q);
        }
    }
    visit[node] = 0; // ����  
    q.pop_back(); // �Ƴ���ǰ�ڵ�  
    
}

string Undigraph::show_message(string tar) {
    if (message.find(tar) == message.end()) return"�õص㲻����";
    return this->message[tar];
}

Undigraph::~Undigraph() {

    for (int i = 0; i < num_node + 1; i++) {
        delete[] edges[i];
    }
    delete[] edges;
}
