//
// Created by 33503 on 24-11-9.
//

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <iostream>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

class HuffmanTree {
    public:
    struct HNode {
        pair<char, int> c; //char类型存放字符， int类型代表该字符频数即权重
        int parent;
        int left, right;
        int lev; //记录当前结点所在层数，用于层次遍历
    };

    map<char, string> code; //存放赫夫曼编码
    //利用map便于对文本编码时查询字符
    HNode* T;
    int size;

    HuffmanTree( string str);
    void select(int n, int& m1, int& m2);
    void Code_Create(); //根据赫夫曼树生成编码集
    string Code_Decoded(string str); //译码0-1串
    string Code_Coding(string str); //文本编码成0-1串
    void Print_Tree(int root, ofstream& outFile, int space , int height); //打印赫夫曼树
    double Compression_Ratio(string code_encoded, string code_decoded); //计算压缩率
    ~HuffmanTree();
};

//HuffmanTree hfm_tree(string& str);





#endif //HUFFMANTREE_H
