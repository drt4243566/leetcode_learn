//0-9 10-35 a-z
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

int char2int(char c){
    int res=0;
    if(c>='0'&&c<='9'){
        res = c-'0';
    }else{
        res = c-'a'+10;
    }
    return res;
}

char int2char(int num){
    char c;
    if(num>=0&&num<=9){
        c = '0'+num;
    }else{
        c = 'a'+num-10;
    }
    return c;
}

string addNum(string s1,string s2){
    int carry=0;
    string res;
    int len1 = s1.size();
    int len2 = s2.size();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int len = min(len1,len2);
    int i;
    for(i=0;i<len;i++){
        int temp = char2int(s1[i])+char2int(s2[i])+carry;
        carry = temp/36;
        temp = temp%36;
        res.push_back(int2char(temp));
    }
    while(i<len1){
        if(carry>0){
            int temp = char2int(s1[i])+carry;
            carry = temp/36;
            temp = temp%36;
            res.push_back(int2char(temp));
        }
        else{
            res.push_back(s1[i]);
        }
        i++;
    }
    while(i<len2){
        if(carry>0){
            int temp = char2int(s2[i])+carry;
            carry = temp/36;
            temp = temp%36;
            res.push_back(int2char(temp));
        }
        else{
            res.push_back(s2[i]);
        }
        i++;
    }
    if(carry>0){
        res.push_back(int2char(carry));
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    string s1 = "zzz";
    string s2 = "1";
    cout << addNum(s1,s2) << endl;
    return 0;
}