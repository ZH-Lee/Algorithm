//
// Created by lee on 2019-05-30.
//

#include <iostream>
#include <string>
using namespace std;

//来源于剑指offer
// 正则表达式匹配
// 给定一个string和一个pattern，其中pattern包含'.'和'*'，
// '.'可以表示任意一个字符,'*'表示它前面的那一个字符可以出现0或者多次
// e.g. str: aaa, pattern: ab*ac*a， 这个是可以匹配的
// aaa 和aa.a是不能匹配的


// 思路是：令i和j分别代表str和pattern的位置。
//  1. 当pattern[j+1]!='*'时，如果str[i]==pattern[j]则i++,j++;
//  2. 如果pattern[j+1]=='*'，如果str[i]==pattern[j]或者pattern[j]是'.'，那么我们有3种状况：
//          (1) 当前str[i]!=pattern[j]，这个时候，我们就直接忽略pattern[j] 和它后面的'*' ，则j+=2;
//          (2) 当前pattern[j]是'.'，我们可以看成str[i]==pattern[j], 则i+1，
//          因为*可以匹配很多个（如果str有重复值）; [ a{a}aaa a{.}*a ]

//          (3) 当前str[i]==pattern[j], 忽略pattern[j+1]的'*'，则i+1, j+2; [ a{a}a, a{a}*ac*]


bool matchCore(string &str, string &pattern, int i, int j) {
    if (i == str.size() && j == pattern.size()) return true;
    if (i!=str.size() && j == pattern.size()) return false;

    if (pattern[j+1] == '*'){
        if (str[i] == pattern[j] || (i!=str.size() && pattern[j]=='.')){
            return  matchCore(str, pattern, i,j+2) ||
                    matchCore(str,pattern,i+1,j+2)||
                    matchCore(str,pattern, i+1, j); // str: a{a}a, pat: a{.}*
        }
        else{
            return matchCore(str,pattern, i,j+2);
        }
    }
    if (str[i] == pattern[j] || (i != str.size() && pattern[j] == '.'))
        return matchCore(str,pattern, i+1, j+1);
    return false;
}

bool match(string &str, string &pattern){
    if(str.empty() || pattern.empty()) return false;
    return matchCore(str, pattern,0,0);
}

int main(){
    string str = "aaa";
    string pat = "aa.a";
    cout << match(str,pat)<<endl;
    return 0;
}
