//
// Created by lee on 2019-05-19.
//

#include<iostream>
#include <vector>
#include <stack>
using namespace std;

bool isValid(string s){
    for (char c : s){
        if (c != '+' || c != '-' || c!='*' || c < '0' || c > '9' || c != '(' || c!=')') return false;
    }
    return true;
}

int cmp(char x)//用来比较符号的优先级
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*')
        return 2;
    if (x == '(')
        return 3;
    if (x == ')')
        return 0;
}

void cal(stack<int> &s1, char c){
    int a = s1.top(); s1.pop();
    int b = s1.top(); s1.pop();
    if (c == '+') s1.push(a+b);
    else if(c=='*') s1.push(a*b);
    else if(c=='-') s1.push(b-a);

}
int convert(string s){
    if (!isValid(s)) return -1;
    stack<char> mystack;
    stack<int> numstack;
    int num = 0;
    bool flag = false;
    for (char c : s){
        if (c >= '0' && c <= '9'){
            num = num * 10 + (c-'0');
            flag = true;
        }
        else{
            if (flag) numstack.push(num);
            num = 0;
            flag = false;
            if(c == '(') {
                mystack.push('(');
                continue;
            }
            while(!mystack.empty() && mystack.top() !='(' && cmp(mystack.top()) > cmp(c)){
                char t = mystack.top();mystack.pop();
                cal(numstack, t);
            }
            if(c == ')') continue;
            mystack.push(c);
        }
    }
    if (num!=0) {
        numstack.push(num);
    }
    while(numstack.size() > 1 && !mystack.empty()){
        if(mystack.top() == '(') mystack.pop();
        cal(numstack, mystack.top());
        mystack.pop();
    }
    return numstack.top();
}
