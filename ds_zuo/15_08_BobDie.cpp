#include <iostream>
#include <cmath>
using namespace std;
long gcd(long m, long n) {
    return n == 0 ? m : gcd(n, m % n);
}
long process(int N, int M, int row, int col, int rest) {
    if(row < 0 || row == N || col < 0 || col == M) {
        return 0;
    }
    if(rest == 0) {
        return 1;
    }
    long live = process(N, M, row - 1, col, rest - 1);
    live += process(N, M, row + 1, col, rest - 1);
    live += process(N, M, row, col - 1, rest - 1);
    live += process(N, M, row, col + 1, rest - 1);
    return live;
}
int bob1(int N, int M, int i, int j, int K) {
    long all = (long)pow(4, K);
    long live = process(N, M, i, j, K);
    long g = gcd(all, live);
    cout << live/g << "/" <<all/g<<endl;
}

int bob2Dp(int N, int M, int i, int j, int K) {
    int dp[N + 2][M + 2][K + 1];
    for(int i=0; i < N + 2;i++){
        for(int j=0;j<M+2;j++) {
            for(int k = 0 ;k<K+1;k++){
                dp[i][j][k] = 0;
            }
        }
    }
    for(int row=1; row<= N;row++){
        for(int col=1;col<=M;col++) {
            dp[row][col][0] = 1;
        }
    }
    for(int rest = 1; rest <= K; rest++) {
        for(int row = 1; row <= N; row ++) {
            for(int col = 1; col <=M; col++) {
                dp[row][col][rest] = dp[row-1][col][rest-1];
                dp[row][col][rest] += dp[row+1][col][rest-1];
                dp[row][col][rest] += dp[row][col-1][rest-1];
                dp[row][col][rest] += dp[row][col+1][rest-1];
            }
        }
    }
    long all = pow(4,K);
    long live = dp[i+1][j+1][K];
    long g = gcd(all, live);
    cout << live/g << "/" <<all/g<<endl;
}
int main(){
    int N = 10;
    int M = 10;
    int i = 3;
    int j = 2;
    int K = 5;
    bob1(N, M, i, j, K);
    bob2Dp(N, M, i, j, K);
    return 0;
}
