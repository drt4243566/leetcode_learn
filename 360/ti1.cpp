#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

struct num{
    int x;
    int y;
    num(int _x,int _y):x(_x),y(_y){}
    bool operator==(num const&other){
        return x==other.x&&y==other.y;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> a(n,0);
    int sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    unordered_map<num,int> mp;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(mp[i][j]>0){
                sum+=dp[i][j];
            }
            else{
                dp[i][j] = a[i]|a[j];
                sum+=dp[i][j];
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}