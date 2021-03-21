#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string,int> con;
unordered_map<string, int> okStr;
int ok(string str) {
    //cout<<str;
    if(okStr.count(str)) return okStr[str];
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
    okStr[str] = abs(cur);
    //cout <<" : "<<cur<<endl;
    return abs(cur);
}
string alls(string cmd, int index, int rest) {
    return cmd + '_' + to_string(index) + '_' + to_string(rest);
}
int process(string cmd, int index, int rest) {
    if(rest == 0) return ok(cmd);
    if(index == cmd.size()) return INT_MIN;
    string tems = alls(cmd,index,rest);
    int ma;
    if(con.count(tems)) {
        ma = con[tems];
    } else {
        ma = process(cmd,index+1,rest);
        con[alls(cmd,index+1,rest)] = ma;
    }
    for(int i=0; i<rest; i++) {
        cmd[index] = (cmd[index]=='F'?'T':'F');
        tems = alls(cmd,index+1, rest-i-1);
        int v;
        if(con.count(tems)) {
            v = con[tems];
        } else {
            v = process(cmd, index+1, rest-i-1);
            con[tems] = v;
        }
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
