using namespace std;
// 经典约瑟夫环问题
// 问题(n,m)表示在0-n-1的数字环上，删除第m个元素；
// 当m固定时，f(n)=(f(n-1)+t)%n;    --此处的t=m%n,表示在删除掉第m个元素之后，重置的数字环的新起点
// 化简后 f(n)=(f(n-1)+m)%n;      -- f(1)的值为0，不管m的值是多少 —— 称之为(1,m)问题

class Solution {
public:
    int lastRemaining(int n, int m) {
        // dp[0]表示(1,m)问题
        int x=0;
        for(int i=2;i<=n;i++){
            x = (x+m)%i;
        }
        return x;
    }
};