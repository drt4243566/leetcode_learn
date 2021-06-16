// 括号字符串的最长有效长度
#include <stack>
#include <iostream>
#include <string>
const int MAXSTR = 1e5;
using namespace std;

struct node{
    char c;
    int index;
};

// 栈解法,顺序遍历字符串，当前为右括号时，栈顶元素刚好为左括号，就弹出
int main(){
    string s;
    cin >> s;
    int res=0;
    stack<node> stk;
    for(int i=0;i<s.size();i++){
        if(s[i]==')'&&!stk.empty()&&stk.top().c=='('){
            stk.pop();
            //int b=0;
            if(!stk.empty()){
                res = max(res,i-stk.top().index);
            }
            // 如果弹出栈顶的(之后为空说明正好配对完成，此时有效长度为i+1
            else{
                res=i+1;
            }
        }
        else{
            stk.push(node{s[i],i});
        }
    }
    cout << res << endl;
    return 0;
}