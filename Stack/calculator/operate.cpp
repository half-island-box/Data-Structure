//
// Created by 33503 on 24-10-5.
//

#include "calculator.h"

type operate(type a, char op, type b){
    //switch-case语法快速匹配各运算符相应操作
    switch (op) {
        case('+'):
            return a + b;
            break;
        case('-'):
            return a-b;
            break;
        case('*'):
            return a*b;
            break;
        case('/'):
            return a/b;
            break;
        default:
            cout<<"operate error"<<endl;
            exit(0);
    }

}

