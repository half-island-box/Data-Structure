//
// Created by 33503 on 24-11-10.
//

#include"HuffmanTree.h"
#include<fstream>
#include<map>
#include<algorithm>
using namespace std;

HuffmanTree hfm_tree(string& str) {
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


    HuffmanTree tree(freq, freq.size()-1); //根据文本构建一棵树
    tree.Code_Create();
    return tree;

}