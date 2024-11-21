//
// Created by 33503 on 24-11-9.
//

#include"HuffmanTree.h"
#include<fstream>
#include<sstream>
#include<iomanip>



HuffmanTree::HuffmanTree(string str) {

    //map类型构建字符频数的字典
    map<char,int> freq;
    for(int i=0; i<str.length(); i++) {
        if(str[i]=='\r') continue; //\r和\n都会产生换行，只记录一个即可
        if(freq.find(str[i])==freq.end()) {
            freq[str[i]]=1;
        }
        else {
            freq[str[i]]++;
        }
    }

    int n=freq.size()-1;
    this->size=n;
    int m=2*n-1;
    this->T=new HNode [m+1];
    //前n个存放叶子节点 其余空间用于构造
    int i=1;
    for(map<char,int>::iterator it=++freq.begin();it!=freq.end();it++){
        T[i].left=T[i].right=T[i].parent=0;
        T[i].c=*it;
        i++;
    }

    for(int i=n+1; i<=m; i++) {
        T[i].c.first='#';
        T[i].c.second=0;
        T[i].left=T[i].right=T[i].parent=0;
        T[i].lev=1;
    }
    //在初始节点的后面构造
    //parent==0代表还没被构造

    int m1, m2;
    for(int i=n+1; i<=m; i++) {
        select(i-1, m1, m2); //找出最小和次小
        int w=T[m1].c.second+T[m2].c.second;
        T[i].c.second=w;
        T[m1].parent=T[m2].parent=i;
        T[i].left=m1;
        T[i].right=m2;
    }

}

//用于找出parent==0的最小和次小节点
void HuffmanTree::select(int n, int& m1, int& m2) {
    int m;
    for(int i=1; i<=n; i++) {
        if(T[i].parent==0) {
            m=i;
            break;
        }
    }

    for(int i=1; i<=n; i++) {
        if(T[i].parent==0 && T[i].c.second<T[m].c.second) m=i;
        else continue;
    }
    m1=m;

    for(int i=1; i<=n; i++) {
        if(T[i].parent==0 && i!=m1) {
            m=i;
            break;
        }
    }

    for(int i=1; i<=n; i++) {
        if(T[i].parent==0 && T[i].c.second<T[m].c.second && i!=m1) {
            m=i;
        }
    }
    m2=m;

}

//根据data.freq.txt生成赫夫曼编码
void HuffmanTree::Code_Create() {

    int cur,pre;
    //从各个叶子节点回溯到根节点构造编码，最后翻转编码字符串
    for(int i=1; i<=size; i++) {

        cur=i;
        pre=T[i].parent;
        while(pre!=0) { //向上回溯过程
            if(T[pre].left==cur) code[T[i].c.first]+='0';
            else if(T[pre].right==cur) code[T[i].c.first]+='1';
            cur=pre;
            pre=T[pre].parent;
        }
        reverse(code[T[i].c.first].begin(), code[T[i].c.first].end());
    }

    // for(int i=1; i<=size; i++) {
    //     if(T[i].c.first==' ') {
    //         cout<<"blank"<<" "<<code[T[i].c.first]<<endl;
    //         continue;
    //     }
    //     if(T[i].c.first=='\n') {
    //         cout<<"enter"<<" "<<code[T[i].c.first]<<endl;
    //         continue;
    //     }
    //     if(T[i].c.first=='\r') {
    //         cout<<"r"<<" "<<code[T[i].c.first]<<endl;
    //         continue;
    //     }
    //
    //
    //     cout<<T[i].c.first<<" "<<code[T[i].c.first]<<endl;
    // }

}

//根据生成的编码对data_source.txt进行编码
string HuffmanTree::Code_Coding(string str) {
    string code_str="";
    for(int i=0; i<str.length(); i++) {
        code_str+=code[str[i]];
        //直接在map中查询对应字符的编码后插入字符串
    }
    return code_str;
}

//对data_source.txt的编码进行译码
string HuffmanTree::Code_Decoded(string str) {
    int cur;
    int root;
    for(int i=1; i<=2*this->size-1; i++) {
        if(this->T[i].parent==0) root=i;
    }
    //找到树的根结点, 即parent==0的结点
    //从根节点追溯，每次追溯到一个叶子结点输出该字符，
    //并回到根节点进行下一次追溯
    string code_decoded="";
    cur=root;
    for(int i=0; i<str.length(); i++) {
        if(T[cur].left==0 && T[cur].right==0) {
            code_decoded+=T[cur].c.first;
            cur=root;
        }
        //根据编码选择深入左右子树
        if(str[i]=='0') cur=T[cur].left;
        else if(str[i]=='1') cur=T[cur].right;
    }
    //考虑最后一个字符没输出的情况
    if(T[cur].left==0 && T[cur].right==0) {
        code_decoded+=T[cur].c.first;
        cur=root;
    }
    return code_decoded;
}

void HuffmanTree::Print_Tree(int root, ofstream& outFile, int space = 0, int height = 8) {
    if (root==0)
        return;

    // 递归打印右子树
    this->Print_Tree( T[root].right, outFile, space + height);

    // 打印当前结点
    outFile << endl;
    outFile << setw(space) << " ";  // 设置缩进
    if(T[root].c.first=='\n') outFile << "Enter"<<"["<<to_string(T[root].c.second)<<"]"<< endl;
    else if(T[root].c.first==' ') outFile << "Space"<<"["<<to_string(T[root].c.second)<<"]"<< endl;
    else outFile << T[root].c.first<<"["<<to_string(T[root].c.second)<<"]"<< endl;

    // 递归打印左子树
    this->Print_Tree(T[root].left, outFile, space + height);
}


HuffmanTree::~HuffmanTree() {
    delete[] T;
    this->code.clear();
}

