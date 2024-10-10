//
// Created by 33503 on 24-9-30.
//

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include<iostream>
using namespace std;
typedef double type;

int relation(char c1, char c2); //返回两个运算符的关系, 1、0、-1分别代表>、=、<
type operate(type a, char op, type b); //对两数进行指定运算符的计算，并返回结果
void evaluate_expression(string& str);//对表达式字符串进行拆解提取
#endif //CALCULATOR_H
