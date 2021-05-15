#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
using namespace std;

// 广度优先遍历
// 很重要的一点是只需要通过向下和向右就可以访问所有连通的点 ———— 连通性
class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        vector<vector<int>> visit(m, vector<int>(n,0));     //二维数组初始化，甚至在函数返回语句当中，vector<int>{1,2,3} 返回临时变量
        visit[0][0] = 1;

        //  转移表，类似于链表里的next
        int dx[2] = {0,1};
        int dy[2] = {1,0};
        int res = 1;
        while(!q.empty()){
            auto [x,y] = q.front();   // 奇特的写法，将pair的元素直接输出
            q.pop();
            for(int i=0;i<2;i++){
                int tx = x + dx[i];
                int ty = y + dy[i];
                if(tx<0||tx>=m||ty<0||ty>=n||visit[tx][ty]||get(tx)+get(ty)>k) continue;
                // 满足条件的点
                q.push(make_pair(tx,ty));
                visit[tx][ty] = 1;
                res++;
            }
        }
        return res;
    }
    // 计算数位和
    int get(int n){
        int res = 0;
        while(n>0){
            res += n%10;
            n /= 10;
        }
        return res;
    }
    
};

// DFS算法 + 数位和增量算法
class SolutionDFS{
public:
    int movingCount(int m, int n, int k){
        this->m = m;
        this->n = n;
        this->k = k;
        visit = vector<vector<bool>>(m, vector<bool>(n, 0));
        return DFS(0,0,0,0);
    }

private:
    // 深度优先遍历递归函数
    int DFS(int i,int j,int si,int sj){
        // 不符合条件，越界+数位和溢出+重复点(最后判断重复)
        if(i<0||j<0||i>=m||j>=n||si+sj>k||visit[i][j]) return 0;
        // 符合条件的点，设为已访问
        visit[i][j] = true;
        return DFS(i,j+1,si,(j+1)%10==0?sj-8:sj+1)+DFS(i+1,j,(i+1)%10==0?si-8:si+1,sj)+1;
    }
    int m;
    int n;
    int k;
    vector<vector<bool>> visit;
};
// 数位和增量算法，每到进位，s_x+1=s_x-8 ,其余情况正常 +1 即可；

// Amazing 动态规划,从连通性的角度来考虑
class SolDP
{
private:
    int get(int x)
    {
        int res = 0;
        for (; x; x /= 10)
        {
            res += x % 10;
        }
        return res;
    }
public:
    int movingCount(int m, int n, int k)
    {
        if (!k)
            return 1;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 1;
        vis[0][0] = 1;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if ((i == 0 && j == 0) || get(i) + get(j) > k)
                    continue;
                // 边界判断
                if (i - 1 >= 0)
                    vis[i][j] |= vis[i - 1][j];
                if (j - 1 >= 0)
                //  此处为动态规划的转移方程，上和左的节点中有一个已连通，当前节点才能连通
                    vis[i][j] |= vis[i][j - 1];
                ans += vis[i][j];
            }
        }
        return ans;
    }
};