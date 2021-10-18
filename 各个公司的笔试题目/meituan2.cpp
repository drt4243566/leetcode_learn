// 不许ac
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    string str;
    cin >> n;
    cin >> str;
    int flag = 0;
    int res = 0;
    int step = 0;
    while(1){
        flag = 0;
        for(int i=step;i<str.size()-1-step;i++){
            if(str[i]=='a'&&str[i+1]=='c'){
                flag = 1;
                res++;
                str[i] = 'c';
                str[i+1] = 'a';
            }
        }
        if(flag==0){
            break;
        }
        step++;
    }
    cout << res << endl;
    return 0;
}