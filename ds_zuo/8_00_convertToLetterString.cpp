#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
string getnewpath(const string &str, int index, int n, string path){
    string temp;
    int num;
    istringstream stream1(str.substr(index,n));
    stream1>>num;
    temp = path + char(num+97);
    return temp;
}
void process(const string &str, int index, string path, vector<string> &ans){
    if(index==str.size()){
        ans.push_back(path);
        return;
    }
    if(str[index]=='0'){
        return;
    }
    if(str[index]=='1'){
        process(str, index+1, getnewpath(str,index,1,path), ans);
        if(index+1<str.size()){
            process(str,index+2,getnewpath(str,index,2,path),ans);
        }
        return;
    }
    if(str[index]=='2'){
        process(str, index+1,getnewpath(str,index,1,path),ans);
        if(index+1<str.size() and (str[index+1]>='0' and str[index+1]<='6')){
            process(str,index+2,getnewpath(str,index,2,path),ans);
        }
        return;
    }
    process(str, index+1,getnewpath(str,index,1,path),ans);

}
void convertToLetterString(const string &str){
    if(str.size()==0){
        return;
    }
    vector<string> ans;
    string path="";
    process(str,0,path,ans);
    cout<<"size:"<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}
int main(){
    //a~k 对应1~26
    string str = "987456";
    //cout<<getnewpath(str,0,1,"")<<endl;
    convertToLetterString(str);
    return 0;
}
