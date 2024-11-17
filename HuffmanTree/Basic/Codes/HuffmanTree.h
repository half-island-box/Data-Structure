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

    HuffmanTree(map<char,int>& arr, int n);
    void select(int n, int& m1, int& m2);
    void Code_Create();
    string Code_Decoded(string str);
    string Code_Coding(string str);
    void Print_Tree(int root, ofstream& outFile, int space , int height);
    ~HuffmanTree();
};

HuffmanTree hfm_tree(string& str);





#endif //HUFFMANTREE_H
