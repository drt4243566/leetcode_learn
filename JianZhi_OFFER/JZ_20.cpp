#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    bool isNumber(string s){
        if(s.size()==0) return false;
        // 设置好标记，分别是数字0~9，点，e和E以及最后的+-符号
        bool isNum(false),isDot(false),ise_or_E(false);
        // 去除首尾的空格
        trim(s);
        for(int i=0;i<s.size();i++){
            // 当前是否数字位？
            if(s[i]>='0'&&s[i]<='9') isNum=true;
            // 当前为小数点
            else if(s[i]=='.'){
                // 如果重复出现小数点，或者在小数点之前出现e，不合格
                if(isDot||ise_or_E) return false;
                isDot = true;
                //isNum = false;   如果重置isNum，则1.这样的数字无法通过判断
            }
            // 当前为e，前面必须是数字，且不能重复出现e
            else if(s[i]=='e'||s[i]=='E'){
                if(!isNum || ise_or_E) return false;
                ise_or_E = true;
                isNum = false;    // e或者E必须后面再跟一个数字
            }
            else if(s[i]=='+'||s[i]=='-'){
                if(i>0 && s[i-1]!='e' && s[i-1]!='E') return false;
            }
            else return false;
        }
        return isNum;
    }
    // 去除字符串首尾空格的函数
    void trim(string &s){
        if(s.empty()){
            return;
        }
        // STL的删除函数，erase(pos-初始位置,n-删除长度)
        s.erase(0,s.find_first_not_of(" "));
        // 只给出第一个参数，则后面位置全部删除
        s.erase(s.find_last_not_of(" ")+1);
    }
};

int main(){
    string s = " dfdffd  ";
    Solution sol;
    cout<<s<<"end"<<endl;
    sol.trim(s);
    cout << s << "end" << endl;
}