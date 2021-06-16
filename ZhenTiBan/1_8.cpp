// 打怪兽

#include <iostream>
#include <vector>
using namespace std;

int beatMonster1(vector<int>& ability,vector<int>& money){
    if(ability.size()!=money.size()) return 0;
    int N = ability.size();
    int sum =0;
    for(int i=0;i<N;i++){
        sum += ability[i];
    }
    vector<vector<int>> dp(N,vector<int>(sum+1,-1));
    // 先安排第一行的值--第一个怪兽只能贿赂，只有能力值刚好等于0位置处的怪兽才能通过
    dp[0][ability[0]] = money[0];
    // 第一列能力值为0，必然完全无法通过，均为-1；

    for(int i=1;i<N;i++){
        for(int j=1;j<=sum;j++){
            if(j<ability[i]) dp[i][j] = -1;
            // j的能力值可以通过
            else{
                // 不需要贿赂当前怪兽
                int p1 = dp[i-1][j];
                // 贿赂当前怪兽
                int p2 = -1;
                if(dp[i-1][j-ability[i]]!=-1){
                    p2 = dp[i-1][j-ability[i]] + money[i];
                }
                dp[i][j] = (p1==-1||p2==-1)?(p1==-1?p2:p1):min(p1,p2);
            }
        }
    }
    int res=INT_MAX;
    for(int k=1;k<=sum;k++){
        res = dp[N-1][k]==-1?res:min(res,dp[N-1][k]); 
    }
    return res;
}

// 将二维dp数组变为一维，注意j的方向要从右向左，避免修改左侧数据
int beatMonster2(vector<int>& ability,vector<int>& money){
    if(ability.size()!=money.size()) return 0;
    int res=INT_MAX;
    int N = ability.size();
    int sum=0;
    for(int i=0;i<N;i++){
        sum += ability[i];
    }
    // 优化为
    vector<int> dp(sum+1,-1);
    dp[ability[0]] = money[0];
    for(int i=1;i<N;i++){
        for(int j=sum;j>=1;j--){
            if(j<ability[i]) dp[j]=-1;
            else{
                int p1 = dp[j];
                int p2=-1;
                if(dp[j-ability[i]]!=-1){
                    p2 = dp[j-ability[i]]+money[i];
                }
                dp[j] = (p1==-1||p2==-1)?(p1==-1?p2:p1):min(p1,p2);
            }
        }
    }
    for(int k=1;k<=sum;k++){
        res = (dp[k]==-1)?res:min(res,dp[k]);
    }
    return res;
}

int main(){
    int N=0;
    cin >> N;
    vector<int> ability(N,0);
    vector<int> money(N,0);
    for(int i=0;i<N;i++){
        cin >> ability[i] >> money[i];
    }
    int res = beatMonster1(ability, money);
    cout << res;
    return 0;
}