#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int process(string s){
    int i=-1;
    int res = 0;
    unordered_map<char,int> dic;
    for(int j=0;j<s.size();j++){
        if(dic.find(s[j])!=dic.end()){
            i = max(i,dic[s[j]]);
        }
        dic[s[j]] = j;
        res = max(res,j-i);
    }
    return res;
}


int process2(string s){
    // dic里面存储的是最近的s[j]字符所在的下标位置
    unordered_map<char,int> dic;
    int res = 0;
    int i=-1;
    for(int j=0;j<s.size();j++){
        if(dic.find(s[j])!=dic.end()){
            i = max(i,dic[s[j]]);
        }
        dic[s[j]] = j;
        res = max(res,j-i);
    }
    return res;
}