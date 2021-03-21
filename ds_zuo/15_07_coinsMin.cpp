#include <iostream>
#include <vector>
using namespace std;
int process(vector<int> arr, int index, int rest) {
    if(index == arr.size()) {
        return rest == 0 ? 1 : 0;
    }
    int ways = 0;
    for(int zhang = 0; arr[index] *zhang <= rest; zhang++) {
        ways += process(arr, index + 1, rest - arr[index] * zhang);
    }
    return ways;
}
int ways1(vector<int> arr, int aim) {
    return process(arr, 0, aim);
}

int ways2(vector<int> arr, int aim) {
    if(arr.size()==0) return 0;
    int N = arr.size();
    int dp[N+1][aim+1];
    for(int i=0;i<N+1;i++) {
        for(int j=0;j<aim+1;j++) {
            dp[i][j] = 0;
        }
    }
    dp[N][0] = 1;
    for(int index = N-1; index >=0; index--) {
        for(int rest = 0; rest <=aim; rest ++) {
            int ways = 0;
            for(int zhang=0;arr[index]*zhang <=rest; zhang++) {
                ways += dp[index + 1][rest-arr[index]*zhang];
            }
            dp[index][rest] = ways;
        }
    }
    return dp[0][aim];
}

int ways3(vector<int> arr, int aim) {
    if(arr.size()==0) return 0;
    int N = arr.size();
    int dp[N+1][aim+1];
    for(int i=0;i<N+1;i++) {
        for(int j=0;j<aim+1;j++) {
            dp[i][j] = 0;
        }
    }
    dp[N][0] = 1;
    for(int index = N-1; index >=0; index--) {
        for(int rest = 0; rest <=aim; rest ++) {
            dp[index][rest] = dp[index + 1][rest];
            if(rest-arr[index] >= 0) {
                dp[index][rest] += dp[index][rest-arr[index]];
            }
        }
    }
    return dp[0][aim];
}
int main(){
    vector<int> arr{1,3,5,2,7,8};
    cout << ways1(arr, 35) << endl;
    cout << ways2(arr, 35) << endl;
    cout << ways3(arr, 35) << endl;
    return 0;
}
