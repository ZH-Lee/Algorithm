//
// Created by lee on 2019-05-21.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// https://leetcode.com/problems/valid-parenthesis-string/submissions/
// 题意是给定一个字符串，只包含*和()，*可以代表空或者(或者),求这个括号字符串是否是有效的。

bool checkValidString(string s) {
    int left = 0, right = 0;
    for (auto c : s){
        left += (c == '(' || c=='*') ? 1 : -1;
        right += (c==')' || c=='*') ? -1  : 1;
        if (left < 0) return false;
        right = max(0, right);
    }
    return right == 0;
}

// 求给定的括号字符串的最大深度，()()()深度为1，((()))深度为3，(())()深度为2
int deep(string s){
    int count = 0;
    int max_ = 0;
    for (auto c : s){
        if (c == '('){
            max_ = max(max_,++count);
        }
        else{
            count--;
        }
    }
    return max_;
}

// 求有效括号子字符串的最大长度，((()()))()为10
int maxlength(string s){
    int pre = 0;
    int res = 0;
    vector<int> dp(s.size(),0);
    for (int i = 0 ;i < s.size(); i++){
        if(s[i]==')'){
            pre = i - dp[i-1]-1;
            if (pre >= 0){
                res += dp[i-1] + 2 + (pre > 0 ? dp[pre-1]: 0);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}


int main(){
    cout << maxlength("((()())")<<endl;
    return 0;
}