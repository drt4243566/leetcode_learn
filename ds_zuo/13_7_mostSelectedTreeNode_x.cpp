#include <iostream>
using namespace std;
typedef long long LL;
LL node[100005],L[100005],R[100005];
LL dp[100005],a[100005],cnt;
int N;
void dfs(int i) {
    if(i==0){
        return;
    } 
    a[++cnt] = node[i];
    dfs(R[i]);
    dfs(L[i]);
}
int getMaxLength() {
    dfs(1);
    /* 求最长上升子序列 */
    int now = 0;
    dp[++now] = a[1];
    for(int i=2;i<=cnt;i++) {
        if(a[i]>dp[now]){
            dp[++now] = a[i];
        } else {
            int k = lower_bound(dp+1,dp+1+now,a[i]) - dp;
            dp[k] = a[i];
        }
    }
    return now;

}
int main(){
    /* 其他方法：后序遍历，求最长下降子序列*/
    cin >> N;
    for(int i=1; i<=N;i++) {
        cin >> node[i];
    } 
    for(int i=1; i<=N;i++) {
        cin >> L[i];
        cin >> R[i];
    } 
    cout << getMaxLength() <<endl;
    return 0;
}
