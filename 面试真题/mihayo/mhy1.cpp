#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MinSum=INT_MAX;
int recur(vector<int>& prices,int cur,int n,int target){
    if(cur==n) return 0;
    int tmp1 = recur(prices,cur+1,n,target)+prices[cur];
    if(tmp1>=target) MinSum = min(tmp1,MinSum);
    int tmp2 = recur(prices,cur+1,n,target);
    if(tmp2>=target) MinSum = min(tmp1,MinSum);
    return max(tmp1,tmp2);
}

int main(){
    int n=0,m=0;
    cin>>n>>m;
    vector<int> prices(n,0);
    for(int i=0;i<n;i++){
        cin >> prices[i];
    }
    recur(prices,0,n,m);
    cout << MinSum;
    return 0;
}