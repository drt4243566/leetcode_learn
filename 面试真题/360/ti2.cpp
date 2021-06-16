#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int,int> mp;
vector<vector<int>> dp(100,vector<int>(100,-1));
vector<int> dic;
int N,M,K;
int recur(int idx,int coins,int K){
    if(dp[idx][K]!=-1){
        return dp[idx][K];
    }
    if(K==0){
        return coins;
    }
    int maxcoins = 0;
    for(int i=idx+1;i<dic.size();i++){
        for(int num=1;num<=K;num++){
            if(dic[i]-dic[idx]<=num*M){
                int temp = recur(i,coins+mp[i],K-num);
                maxcoins = max(maxcoins,temp);
            }
        }
    }
    dp[idx][K] = maxcoins;
    return maxcoins;
}
int main(){
    cin>>N;
    cin>>M;
    cin>>K;
    int coin,distance;
    for(int i=0;i<N;i++){
        cin >> distance >>coin;
        mp[i] = coin;
        dic.push_back(distance);
    }
    int coins = mp[0];
    int maxcoins = recur(0,coins,K);
    cout <<maxcoins<<endl;
    return 0;
}