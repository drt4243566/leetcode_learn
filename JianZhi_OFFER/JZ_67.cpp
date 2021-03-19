#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    int strToInt(string str) {
        int res=0,bndry=INT_MAX/10;
        // 设置一个索引，符号位变量
        int i=0,sign=1,len=str.size();
        if(len==0) return 0;
        // 1.排除最开始处的空格
        while(str[i]==' '){
            i++;
            if(i==len) return 0;
        }
        if(str[i]=='-') sign=-1;
        if(str[i]=='+'||str[i]=='-') i++;
        for(int j=i;j<len;j++){
            // 2.遇到非数字的情况，直接返回
            if(str[j]<'0'||str[j]>'9') break;
            // 3.数字溢出的情况
            if(res>bndry||(res==bndry&&str[j]>'7')){
                return sign==1?INT_MAX:INT_MIN;
            }
            // 4.正常情况下，原先数字乘10后继续累加
            res = res*10+(str[j]-'0');
        }
        return sign*res;
    }
};