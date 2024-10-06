//
// Created by 33503 on 24-9-30.
//

#include<iostream>
#include<string>
#include"calculator.h"
using namespace std;

void test() {
    string str;
    cin>>str;
    evaluate_expression(str);
}

int main() {
    test();
    return 0;
}