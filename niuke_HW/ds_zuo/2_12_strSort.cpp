/*
规则 1 ：英文字母从 A 到 Z 排列，不区分大小写。
如，输入： Type 输出： epTy
规则 2 ：同一个英文字母的大小写同时存在时，按照输入顺序排列。
如，输入： BabA 输出： aABb
规则 3 ：非英文字母的其它字符保持原来的位置。
如，输入： By?e 输出： Be?y
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
void strSort1(){
    string str;
    while(getline(cin,str)){
        vector<char> letter;
        for(int i=0;i<26;i++){
            for(int j=0;j<str.size();j++){
                if((str[j]-'a' == i) || (str[j]-'A' ==i)){
                    letter.push_back(str[j]);
                }
            }
        }
        for(int i=0,j=0;i<str.size();i++){
            if(isalpha(str[i])){
                str[i] = letter[j++];
            }
        }
        cout<<str<<endl;
    }
}

void strSort2(){
    string str;

    while(getline(cin,str)){
        vector<vector<char>> V;
        for(int i=0; i<str.size(); i++){
            
        }
    }
}
int main(){
    strSort1();
    return 0;
}