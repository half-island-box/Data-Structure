
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

    nodes[1] = "生命科学楼";
    nodes[2] = "校训";
    nodes[3] = "黑石屋";
    nodes[4] = "怀士堂";
    nodes[5] = "陈寅恪故居"; 
    nodes[6] = "孙中山纪念馆";
    nodes[7] = "孙中山铜像";
    nodes[8] = "松涛园";
    nodes[9] = "北门石牌";
    nodes[10] = "广寒宫";

    cast["生命科学楼"] = 1;
    cast["校训"] = 2;
    cast["黑石屋"] = 3;
    cast["怀士堂"] = 4;
    cast["陈寅恪故居"] = 5;
    cast["孙中山纪念馆"] = 6;
    cast["孙中山铜像"] = 7;
    cast["松涛园"] = 8;
    cast["北门石牌"] = 9;
    cast["广寒宫"] = 10;


    message["生命科学楼"] = "位于中山大学南门西侧，隶属于中山大徐生命科学学院。";
    message["校训"] = "中山大学校徽和校训，游客必打卡。";
    message["黑石屋"] = "芝加哥的伊沙贝·布勒斯顿（黑石）夫人出资为担任过岭南学堂教务长和岭南大学校长的钟荣光博士（岭南大学首位华人校长）修建的寓所。是中大红楼的代表。";
    message["怀士堂"] = "中山大学标志性建筑，孙孙中山先生在此发表名句“立志做大事，不可做大官。";
    message["陈寅恪故居"] = "原名麻金墨屋一号，史学大师陈寅恪故居。";
    message["孙中山纪念馆"] = "孙中山纪念馆创建于1953年，在孙中山诞辰八十七周年、中山大学建校二十九周年校庆之际，“孙中山先生纪念室”落成开幕，是新中国成立后中国大陆建立的第一家孙中山纪念机构。";
    message["孙中山铜像"] = "孙中山纪念铜像是在孙中山先生逝世后，孙中山先生的日本友人梅屋庄吉先生在1932年赠送给中国的4具塑像。";
    message["松涛园"] = "位于中山大学南校园东北部，是校园内占地最大，最豪华的食堂。";
    message["北门石牌"] = "位于广州中大海珠校区（即南校区）北门，门额刻有“国立中山大学”六个大字， 系2001年参照原有的国立中山牌坊复制而成。中山大学牌坊一直以来都是广州中山大学的标志。";
    message["广寒宫"] = "由中国妇女和新泽西州岭南之友共同捐建，1933年落成，现为博雅学院宿舍。";



}

void Undigraph::DFS(int node, int visit[]) {
    cout << node << " ";
    visit[node] = 1;
    for (int i = 1; i <= num_node; i++) {
        if (this->edges[node][i] == 1 && visit[i] == 0) { //对该结点的各个邻接点考虑
            DFS(i, visit);
        }
    }
}

//深度优先
void Undigraph::Depth_Print() {
    //int visit[num_node + 1] = {};
    int* visit = new int [num_node + 1] {};
    for (int i = 1; i <= num_node; i++) { //考虑不是连通图的可能性，需要对各个结点遍历
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
        for (int i = 1; i <= num_node; i++) { //插入队头的所有非遍历邻接点
            if (!visit[i] && edges[q.front()][i] == 1) q.push(i);
        }
        q.pop();
    }
}

//广度优先
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
        return "起点和终点不可以重合";
    }
    if (cast.find(begin) == cast.end()) return "输入的起点无效" ;
    int node = cast[begin];
    
    if (cast.find(end) == cast.end()) return "输入的终点无效";
    int tar = cast[end];

    int* dist = new int [num_node + 1] {}; //记录路径长度
    int* path = new int [num_node + 1] {};//记录结点路径上的前驱
    int* s = new int [num_node + 1] {};//记录已经找到最短路径的结点
    fill(dist, dist + num_node + 1, INT_MAX); //数组填充int类型最大数，作为初始化
    dist[node] = 0;
    fill(path, path + num_node + 1, -1);
    s[node] = 1;
    int cnt = 1;
    int newnode = node; //记录每一轮的最短路径顶点
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
                //若最短路径节点+最短路径顶点到该顶点距离<顶点原路径距离->更新路径
                dist[i] = dist[newnode] + edges[newnode][i];
                path[i] = newnode;
                // if(dist[i]<dist[min]) min=i;
            }

        }

        //选出本轮有最短路径的点
        for (int i = 1; i <= num_node; i++) {
            if (s[i] == 0 && dist[i] < dist[min]) min = i;
        }

        newnode = min;
        s[newnode] = 1; //该节点找到了最短路径
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
    if (is == 0) route += nodes[node]; //is用于判断路径是否需要加入起点(用于有途径点时候的调用)
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

//增加途径点的最短路径
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
        cout<< "起点和终点不可以重合"<<endl;
        return;
    }
    if (cast.find(begin) == cast.end()) {
        cout<< "输入的起点无效"<<endl;
        return;
    }


    if (cast.find(end) == cast.end()) {
        cout<< "输入的终点无效";
        return;
    }
    cout << "包括途径点的路径如下：" << endl;
    vector<string> q;
    vector<int> visit(this->num_node, 0); // 使用 vector 自动管理内存  
    dfs(cast[begin], visit.data(), cast[end], q); // 传递 visit 的指针  
}

void Undigraph::dfs(int node, int visit[], int end, vector<string>& q) {
    q.push_back(nodes[node]);
    if (node == end) {
        for (size_t i = 0; i < q.size(); i++) {
            cout << q[i];
            if (i != q.size() - 1) cout << "->";
            else cout << endl;
        }
        q.pop_back(); // 回溯时要移除最后一个节点  
        return; // 找到路径后返回  
    }

    visit[node] = 1;
    for (int i = 1; i <= num_node; i++) { // 从 0 开始遍历  
        if (visit[i] == 0 && edges[node][i] != 0) {
            dfs(i, visit, end, q);
        }
    }
    visit[node] = 0; // 回溯  
    q.pop_back(); // 移除当前节点  
    
}

string Undigraph::show_message(string tar) {
    if (message.find(tar) == message.end()) return"该地点不存在";
    return this->message[tar];
}

Undigraph::~Undigraph() {

    for (int i = 0; i < num_node + 1; i++) {
        delete[] edges[i];
    }
    delete[] edges;
}
