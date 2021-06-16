#include <iostream>
#include <set>
#include <string>
using namespace std;
void process(const string &str, int index, set<string> &ans, string path){
    if(index == str.size()){
        ans.insert(path);
    } else {
        process(str,index+1,ans,path);
        path = path + str[index];
        process(str,index+1,ans,path);
    }
}
void printAllSubsequences(const string &str){
    if(str.size()==0){
        return;
    }
    string path;
    set<string> ans;
    process(str, 0, ans, path);
    for(auto p=ans.begin();p!=ans.end();p++){
        cout<<*p<<endl;
    }
}
int main(){

    string str = "abc";
    printAllSubsequences(str);
    return 0;
}
