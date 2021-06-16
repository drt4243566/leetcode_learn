#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

bool judgeHappy(int N1){
    unordered_set<int> s;
    string s1 = to_string(N1);
    for(int i=0;i<s1.size();i++){
        s.insert(s1[i]);
    }
    bool flag1 = s.count('0');
    bool flag2 = s.count('1');
    if(s.size()>3) return false;
    else if(s.size()==3){
        if(flag1&&flag2) return true;
        else return false;
    }
    else if(s.size()==2) return flag1||flag2;
    else if(s.size()==1) return true;
    else return false;
}

int main(){
    int N;
    cin >> N;
    int carry=1;
    if(N<10){
        cout << N;
        return 0;
    }
    int index=1;
    while(1){
        if(judgeHappy(N*index)){
            cout << N*index;
            break;
        }
        index++;
    }
    return 0;
}
