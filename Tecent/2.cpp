#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    stack<char> stack;
    int i=0;
    while(i<str.size()){
        if(stack.empty()){
            stack.push(str[i]);
            i++;
        }
        else if(stack.top()+str[i]-2+'0'!=10){
            stack.push(str[i]);
            i++;
        }
        else if(stack.top()+str[i]-2+'0'==10){
            stack.pop();
            i++;
        }
    }
    cout<<stack.size();
    return 0;
}