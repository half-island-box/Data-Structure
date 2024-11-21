//
// Created by 33503 on 24-11-9.
//

#include<iostream>
#include"HuffmanTree.h"
#include<fstream>
#include<sstream>
using namespace std;



string source_encoded(HuffmanTree& tree) {
    ifstream src("data_source.txt");
    if(!src) {
        cerr<<"open fail"<<endl;

    }
    char c1;
    src.get(c1);
    //src.get(c2);

    stringstream buffer2;
    buffer2<<src.rdbuf();

    string str2 = buffer2.str();
    src.close();

    string code_str=tree.Code_Coding(str2);
    return code_str;
}







int main() {
    //导入data_freq.txt文件，构造赫夫曼树
    ifstream ifs("data_freq.txt");
    if(!ifs) {
        cerr<<"open fail"<<endl;
    }

    char c1,c2;
    ifs.get(c1);
    ifs.get(c2);

    stringstream buffer;
    buffer<<ifs.rdbuf();
    string str = buffer.str();
    ifs.close();
    HuffmanTree tree(str);
    tree.Code_Create();

    //将编码写入data_encoded.txt
    string code_str=source_encoded(tree);
    ofstream outFile("data_encoded.txt");
    if(outFile.is_open()) {
        outFile<<code_str;
        outFile.close();
        cout<<"write success."<<endl;
    }
    else cerr<<"open fail"<<endl;

    //译码data_encoded.txt，并写入data_decoded.txt
    ifstream inFile("data_encoded.txt");
    if(!inFile) {
        cerr<<"open fail"<<endl;
    }
    stringstream buffer2;
    buffer2<<inFile.rdbuf();
    string code_encoded = buffer2.str();
    inFile.close();
    string code_decoded=tree.Code_Decoded(code_encoded);
    ofstream outFile2("data_decoded.txt");
    if(outFile2.is_open()) {
        outFile2<<code_decoded;
        outFile2.close();
        cout<<"write success."<<endl;
    }
    else cerr<<"open fail"<<endl;

    //打印赫夫曼树
    ofstream outFile3("hfm_tree_print.txt");
    // 确保文件成功打开
    if (!outFile3) {
        cerr << "open fail" << endl;
        return 1;
    }

    // 打印二叉树到文件
    int root;
    for(int i=1; i<=2*tree.size-1; i++) {
        if(tree.T[i].parent==0) {
            root=i;
            break;
        }
    }
    tree.Print_Tree(root, outFile3,0,8);

    // 关闭文件
    outFile3.close();
    cout << "write success" << endl;


    return 0;
}
