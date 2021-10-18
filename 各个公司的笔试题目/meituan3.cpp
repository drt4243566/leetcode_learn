#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> dpa(n+1,0);
    vector<int> dpb(n+1,0);
    vector<int> dp(n+1,0);
    dpa[1] = 1, dpa[2] = 2;
    dpb[1] = 1, dpb[2] = 2;
    dp[1] = 2, dp[2] = 4;
    for(int i=3;i<=n;i++){
        int atmp = 0,btmp = 0;
        btmp = dpb[i-1]+dpa[i-1]-dpb[i-2];
        dpb[i] = btmp%998244353;
        atmp = dpa[i-1] + dpb[i-1]-dpa[i-2];
        dpa[i] = atmp%998244353;
        dp[i] = (dpb[i]+dpa[i])%998244353;
    }
    cout << dp[n];
}