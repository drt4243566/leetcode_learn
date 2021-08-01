// KMP算法
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getNextArr(vector<int>& next,string& s){
    // 用于获取模式串的next数组 -- 相当于是prefix前缀表
    // 指针i表示后缀的末尾，指针j指向的是前缀的末尾，同时也代表[0,i-1]范围上的最长的前缀和后缀相等的长度
    int i=0,j=0;
    //next[0]=0;
    for(i=1;i<s.size();i++){
        // 不相等就连续回退
        while(j>0&&s[i]!=s[j]){
            j = next[j-1];
        }
        // 相等则长度+1
        if(s[i]==s[j]) j++;
        next[i] = j;
    }
    return;
}

int KMP(string& str1,string& str2){
    if(str2.size()==0) return false;
    vector<int> next(str2.size(),0);
    getNextArr(next,str2);
    // i指向str1的指针，j为指向str2的指针
    int i=0,j=0;
    while(i<str1.size()&&j<str2.size()){
        if(str1[i]==str2[j]){
            i++;
            j++;
        }
        else if(j>0){
            j = next[j-1];
        }
        else{
            i++;
        }
    }
    // 返回模式串匹配到的位置
    return j==str2.size()?i-j:-1;
}

int main(){
    string str1 = "aabaabaaf";
    string str2 = "aabaaf";
    int res = KMP(str1,str2);
    cout << res;
    return 0;
}