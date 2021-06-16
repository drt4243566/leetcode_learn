#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

int compare(list<char>::iterator p1,list<char>::iterator p2){
    if(*p1==*p2) return 0;
    if(*p1=='R'){
        if(*p2=='S') return 1;
        if(*p2=='C') return 1;
    }
    if(*p1=='S'){
        if(*p2=='R') return 0;
        if(*p2=='C') return 1;
    }
    if(*p1=='C'){
        if(*p2=='R') return 0;
        if(*p2=='S') return 0;
    }
    return 0;
}

int findCommonList(string& str){
    int res=0;
    int L=0,R=0;
    int MaxLen=0;
    int headLen=0;
    while(R<str.size()){
        if(str[R]==str[L]){
            R++;
            if(R==str.size()){
                int len = R-L;
                if(len>MaxLen){
                    res = L;
                    MaxLen = len;
                    if(res==0) headLen=len;
                    break;
                }
            }
        }
        else{
            int len = R-L;
            if(len>MaxLen){
                res = L;
                MaxLen = len;
                if(res==0) headLen=len;
            }
            L = R;
        }
    }
    int tail=str.size()-1;
    if(str[tail]==str[0]){
        for(;tail>0;tail--){
            if(str[tail]==str[tail-1]){
                headLen++;
            }else{
                if(str[tail]==str[0]) headLen++;
                break;
            }
        }
    }
    if(headLen>MaxLen) res=tail;
    return res;
}

int process(string& str,int N,int M,int startPos){
    list<char> lst(str.begin(),str.end());
    auto p1 = lst.begin();
    for(int i=0;i<startPos;i++){
        p1++;
    }
    while(M--){
        auto p2 = p1;
        p2++;
        if(p2==lst.end()) p2++;
        int a = compare(p1,p2);
        if(a==0){
            p1==p2;
        }
        else if(a>0){
            lst.erase(p2++);
        }
        else{
            lst.erase(p1);
            p1=p2;
        }
    }
    return lst.size();
}


int main(){
    int T=0;
    cin >> T;
    while(T--){
        int N=0,M=0;
        cin >> N >>M;
        string kids;
        cin >> kids;
        int start = findCommonList(kids);
        return process(kids,N,M,start);
    }
    return 0;
}