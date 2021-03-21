#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int process(vector<int> w, vector<int> v, int index, int already, int bag) {
    if (already > bag) {
        return -1;
    }
    if (index == w.size() || already == bag) {
        return 0;
    }
    int L1 = process(w, v, index + 1, already, bag);
    int L2 = -1;
    int L2next = process(w, v, index + 1, already + w[index], bag);
    if (L2next != -1) {
        L2 = v[index] + L2next;
    }
    return max(L1, L2);

}
void knapsack(vector<int> w, vector<int> v, int bag) {
    if (w.empty() or v.empty() or bag <= 0) {
        cerr << "error" << endl;
        return;
    }
    cout << process(w, v, 0, 0, bag)<<endl;
}
void waysDp(vector<int> w, vector<int> v, int bag) {
    int row = w.size();
    int col = bag;
    int dp[row+1][col+1];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<= row; i++) {
        int time = w[i-1];
        int cost = v[i-1];
        for(int j=1; j<= col; j++) {
            if(j < time) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-time]+cost);
            }
        }
    }
    cout << dp[row][col] << endl;
}
int main() {
    int time, num;
    cin >> time >> num;
    vector<int> w, v;
    while (num--) {
        w.push_back(read());
        v.push_back(read());
    }
    knapsack(w, v, time);
    waysDp(w, v, time);
    return 0;
}
/* 背包问题*/