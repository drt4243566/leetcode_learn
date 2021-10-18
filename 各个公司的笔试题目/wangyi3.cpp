#include <vector>
#include <iostream>
using namespace std;

int dfs(vector<vector<int>>& mp,int x,int y){
    int m = mp.size();
    int n = mp[0].size();
    if(x<0||y<0||x>=m||y>=n) return -1;
    if(x==m-1&&y==n-1)
    int cost1 = dfs(mp,x-1,y);
    int cost2 = dfs(mp,x+1,y);
    int cost3 = dfs(mp,x,y-1);
    int cost4 = dfs(mp,x,y+1);
}

int minSailCost(vector<vector<int> >& input) {
        
}

int main(){
    vector<vector<int>> mp;

    return 0;
}

/*
1 1 1 1 0
0 1 0 1 0
1 1 2 1 1
0 2 0 0 1
*/