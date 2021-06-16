#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int res=0;
int m;
void dfs(int num,deque<int>& tem){
    if(num<0)
        return;
    if(num==0){
        res++;
        return;
    }
    for(int i=1;i<=m;i++){
        if(tem.empty()){
            tem.push_back(i);
            dfs(num-i,tem);
            tem.pop_back();
        }
        else if(tem.size()==1){
            if(tem.front()==i) continue;
            else{
                tem.push_back(i);
                dfs(num-i,tem);
                tem.pop_back();
            }
        }
        else{
            if(tem.back()==i||tem.front()==i){
                continue;
            }
            else{
                tem.push_back(i);
                int temp = tem.front();
                tem.pop_front();
                dfs(num-i,tem);
                tem.pop_back();
                tem.push_front(temp);
            }
        }
    }
}
int main(){
    int n;
    cin >> n >> m;
    deque<int> mem;
    dfs(n,mem);
    cout << res%1000000007 <<endl;
    return 0;
}