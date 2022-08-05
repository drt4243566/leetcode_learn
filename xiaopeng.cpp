#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>
using namespace std;


bool escape(const std::vector<std::string> &maze,int i,int j){
    if(maze[i][j]!=' ') return false;
    int m = maze.size();
    int n = maze[i].size();
    if(i==0||i==m-1||j==0||j==n-1){
        return true;
    }
    return false;
}

bool dfs(const std::vector<std::string> &maze,int i,int j){
    if(escape(maze,i,j)) return true;
    int m = maze.size();
    int n = maze[i].size();
    if(i<0||i>=m||j<0||j>=n) return false;
    if(maze[i][j]!='#'){
        return dfs(maze,i-1,j)||dfs(maze,i+1,j)||dfs(maze,i,j-1)||dfs(maze,i,j+1);
    }else{
        return false;
    }
}

bool solution(const std::vector<std::string> &maze) {
  // 这里写代码
    int m = maze.size();
    vector<vector<int>> visit(m,vector<int>(maze[0].size(),0));
    for(int i=0;i<m;i++){
        for(int j=0;j<maze[i].size();j++){
            if(maze[i][j]=='k'){
                return dfs(maze,i,j);
            }
        }
    }
    return false;
}

int main(){
    std::vector<std::string> maze = {"####","#k ","##"};
    bool res = solution(maze);
    std::string result = res?"true":"false";
    std::cout << result << std::endl;
    return 0;
}