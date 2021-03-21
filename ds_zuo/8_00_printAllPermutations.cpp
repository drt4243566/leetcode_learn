#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
void process(const string &str, string path, set<int> isSelect, set<string> &ans){
    if(path.size()==str.size()){
        ans.insert(path);
        return;
    }
    for(int i=0;i<str.size();i++){
        if(!isSelect.count(i)){
            set<int> temp = isSelect;
            temp.insert(i);
            process(str, path+str[i], temp, ans);
        }
    }
}
//重复排列进行优化
void process2(const string &str, string path, set<int> isSelect, vector<string> &ans){
    if(path.size()==str.size()){
        ans.push_back(path);
        return;
    }
    set<char> picks;
    for(int i=0;i<str.size();i++){
        if(!picks.count(str[i]) && !isSelect.count(i)){
            picks.insert(str[i]);
            set<int> temp = isSelect;
            temp.insert(i);
            process2(str, path+str[i], temp, ans);
        }
        
    }
}
void printAllPermutations(const string &str){
    if(str.size() == 0){
        return;
    }
    vector<string> ans;
    string path="";
    set<int> isSelect;
    //process(str, path, isSelect, ans);
    process2(str, path, isSelect, ans);
    for(auto p=ans.begin();p!=ans.end();p++){
        cout<<*p<<endl;
    }
    cout<<ans.size()<<endl;

}
int main(){

    string str = "abc";
    printAllPermutations(str);
    return 0;
}
