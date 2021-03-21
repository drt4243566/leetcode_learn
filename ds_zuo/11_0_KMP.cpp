#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> getNextArray(string ms){
    if(ms.size()==1){
        return vector<int>{-1};
    }
    vector<int> next(ms.size());
    next[0] = -1;
    next[1] = 0;
    int i=2;
    int cn=0;
    while(i<next.size()){
        if(ms[i-1]==ms[cn]){
            next[i++] = ++cn;
        } else if(cn>0){
            cn = next[cn];
        }else{
            next[i++] = 0;
        }
    }
    return next;
}
int getIndexOf(string s, string m){
    if(s.size()<1 or m.size()<1 or s.size()<m.size())
        return -1;
    int i1 = 0;
    int i2 = 0;
    vector<int> next = getNextArray(m);
    while(i1<s.size() and i2<m.size()){
        if(s[i1]==m[i2]){
            i1++;
            i2++;
        }else if(next[i2]==-1){
            i1++;
        }else{
            i2 = next[i2];
        }
    }
    return i2==m.size()?i1-i2:-1;
}

int main(){
    cout<<getIndexOf("zhanghaoyu","haoyu");
    return 0;
}
