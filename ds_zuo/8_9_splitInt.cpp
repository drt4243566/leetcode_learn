#include <iostream>
using namespace std;
int dp[1000][1000];
int main(){
    int N, M;
    cin>>N>>M;
    int i,j;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            if(i==j)
                dp[i][j]=1;
            else
                dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
        }
    }
    cout<<dp[N][M]<<endl;
    return 0;
}
