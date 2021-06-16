#include <iostream>
#include <array>
using namespace std;
int process(int x, int y, int step) {
    if(x<0 || x>8 || y<0 || y>9) {
        return 0;
    } 
    if(step ==0) {
        return (x==0 && y==0)?1:0;
    }
    return process(x - 1, y + 2, step - 1)
        + process(x + 1, y + 2, step - 1)
        + process(x + 2, y + 1, step - 1)
        + process(x + 2, y - 1, step - 1)
        + process(x + 1, y - 2, step - 1)
        + process(x - 1, y - 2, step - 1)
        + process(x - 2, y - 1, step - 1)
        + process(x - 2, y + 1, step - 1);

}
int ways1(int x, int y, int k){
    return process(x, y, k);
}

int dp[9][10][100];
int getValue(int row, int col, int step) {
    if(row<0 || row>8 || col <0||col>9){
        return 0;
    } 
    return dp[row][col][step];
}
int ways2Dp(int x, int y, int step) {
    if(x<0 || x>8 || y<0 || y>9) {
        return 0;
    } 
    dp[0][0][0] = 1;
    for(int h = 1; h<=step; h++) {
        for(int r=0; r<9; r++) {
            for(int c = 0; c<10; c++) {
                dp[r][c][h] += getValue(r - 1, c + 2, h - 1);
                dp[r][c][h] += getValue(r + 1, c + 2, h - 1);
                dp[r][c][h] += getValue(r + 2, c + 1, h - 1);
                dp[r][c][h] += getValue(r + 2, c - 1, h - 1);
                dp[r][c][h] += getValue(r + 1, c - 2, h - 1);
                dp[r][c][h] += getValue(r - 1, c - 2, h - 1);
                dp[r][c][h] += getValue(r - 2, c - 1, h - 1);
                dp[r][c][h] += getValue(r - 2, c + 1, h - 1);
            }
        }
    }
    return dp[x][y][step];
}
int main(){
    cout << ways1(7,7,10)<<endl;
    cout << ways2Dp(7,7,10)<<endl;
    return 0;
}
