//
// Created by 33503 on 24-10-5.
//

#include"calculator.h"
#include<string>
#include<stack>1


void evaluate_expression(string& str) {
    stack<char> OPTR; //运算符栈
    OPTR.push('#');
    stack<type> OPND; //操作数字栈
    int i=0;
    while(str[i]!='#' || OPTR.top()!='#') { //字符为#说明读到末尾 栈顶为#说明运算完毕
        if(str[i]>='0'  && str[i]<='9') { //字符为数字
            type x=(int)(str[i]-'0');
            i++;
            while(str[i]>='0' && str[i]<='9'){ //考虑数字为两位数以上的数字，需要累加
                x*=10;
                x+=(int)(str[i]-'0');
                i++;
            }
            OPND.push(x);
        }
        else {
            int rel= relation(OPTR.top(), str[i]);
            if(rel==-1) { //栈顶优先度低，入栈
                OPTR.push(str[i]);
                i++;
            }
            if(rel==0) { //栈顶和待插入优先度相等，将两个运算符消掉
                OPTR.pop();
                i++;
            }
            if(rel==1) { //栈顶优先度高，进行栈顶运算符计算
                char op=OPTR.top();
                OPTR.pop();

                type a=OPND.top();
                OPND.pop();
                type b=OPND.top();
                OPND.pop();
                OPND.push(operate(b,op,a));

            }


        }
    }
    cout<<OPND.top()<<endl; //计算完毕后数字栈只有运算结果
}

