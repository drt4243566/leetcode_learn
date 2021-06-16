#include <iostream>
#include <string>
using namespace std;
int ok(string str) {
    //cout<<str;
    int cur = 0;
    int f = 1;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == 'F' && f == 1) {
            cur ++;
        } else if(str[i] == 'T' && f == 0) {
            f = 1;
        } else if(str[i] == 'T' && f == 1) {
            f = 0;
        } else if( str[i] == 'T' && f== 1) {
            cur--;
        }
    }
    //cout <<" : "<<cur<<endl;
    return abs(cur);
}
int process(string cmd, int index, int rest) {
    if(rest == 0) return ok(cmd);
    if(index == cmd.size()) return INT_MIN;
    int ma = process(cmd, index+1, rest);
    for(int i=0; i<rest; i++) {
        cmd[index] = (cmd[index]=='F'?'T':'F');
        int v = process(cmd, index+1, rest-i-1);
        ma = max(ma,v);
    }
    return ma;
}
int turtleWalk(string cmd, int rest) {
    if(rest == 0) return ok(cmd);
    return process(cmd, 0, rest);
}
int main(){
    string str;
    cin >> str;
    int n;
    cin >> n;
    cout << turtleWalk(str, n);
    return 0;
}
