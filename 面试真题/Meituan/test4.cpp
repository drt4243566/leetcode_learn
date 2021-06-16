#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
string s;
int compute(int& p,char ch){
    if(p==s.size()){
        p = 0;
    }
    if(ch>=s[p]){
        int num = ch-s[p]+1;
        p = ch-'a'+1;
        return num;
    }else{
        int num = s.size()-p+1+ch-'a';
        p = ch - 'a'+1;
        return num;
    }
}

int main(){
    string str_tar;
    cin >> s;
    cin >> str_tar;
    if(str_tar.size()==0){
        cout<<0<<endl;
        return 0;
    }
    int p=0;
    int sum = 0;
    for(int i=0;i<str_tar.size();i++){
        sum += compute(p,str_tar[i]);
    }
    cout << sum-str_tar.size()<<endl;
    return 0;
}