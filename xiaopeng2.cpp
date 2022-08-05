#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<int,string> process(string str){
    unordered_map<int,string> dic;
    //unordered_map<char,char> kuohao;
    //kuohao['('] = ')';
    //kuohao['['] = ']';
    //kuohao['{'] = '}';
    int level = -1;
    char cur;
    for(int i=0;i<str.size();i++){
        cur = str[i];
        if(cur=='(' || cur=='[' || cur=='{'){
            dic[++level].push_back(cur);
        }
        else{
            dic[level].push_back(cur);
            level--;
        }
    }
    return dic;
}

int main(){
    string str = "[(){[]()}({}())]";
    unordered_map<int,string> dic = process(str);
    cout << dic[0] << endl;
    cout << dic[1] << endl;
    cout << dic[2] << endl;
    return 0;
}