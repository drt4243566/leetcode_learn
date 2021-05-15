#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int MinSum=INT_MAX;

void recur(vector<int>& prices,int cur,int n,int target,int sum){
    if(cur==n){
        MinSum = min(MinSum,sum);
        return;
    }
    if(sum>=target) MinSum = min(sum,MinSum);
    recur(prices,cur+1,n,target,sum+prices[cur]);
    recur(prices,cur+1,n,target,sum);
}

int main(){
    int n=0,m=0;
    cin>>n>>m;
    vector<int> prices(n,0);
    for(int i=0;i<n;i++){
        cin >> prices[i];
    }
    recur(prices,0,n,m,0);
    cout << MinSum;
    return 0;
}