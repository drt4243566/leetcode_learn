#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <queue>
using namespace std;

// dfs强行搜索
class SolutionDfs {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> wordMap;
        for(auto& word:wordDict){
            wordMap[word] = true;
        }
        return canBreak(s,wordMap,0);
    }

    bool canBreak(string s,unordered_map<string,bool> &wordMap,int start){
        if(start==s.size()) return true;
        for(int i=start+1;i<=s.size();i++){
            string prefix = s.substr(start,i-start);
            if(wordMap[prefix]&&canBreak(s,wordMap,i)) return true;
        }
        return false;
    }
};

// dfs记忆化搜素
/*
    核心思想是要有一个start指针控制当前指向的下标，再进行前缀遍历，如果不匹配直接回溯，如果
    匹配则继续进行下一段字符串的判断；
    记忆化的搜索需要根据下标值储存结果；
*/
class SolutionDfs2 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> wordMap;
        vector<int> mem(s.size(),0);
        for(auto& word:wordDict){
            wordMap[word] = true;
        }
        return canBreak(s,wordMap,0,mem);
    }

    bool canBreak(string s,unordered_map<string,bool> &wordMap,int start,vector<int>& mem){
        if(start==s.size()) return true;
        if(mem[start]!=0){
            if(mem[start]>0) return true;
            else{
                return false;
            }
        }
        for(int i=start+1;i<=s.size();i++){
            string prefix = s.substr(start,i-start);
            if(wordMap[prefix]&&canBreak(s,wordMap,i,mem)){
                mem[start] = 1;
                return true;
            }
        }
        mem[start] = -1;
        return false;
    }
};

// bfs强行搜索
class SolutionBfs {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> wordMap;
        for(auto& word:wordDict){
            wordMap[word] = true;
        }
        unordered_map<int,bool> visit;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int start = q.front();
            q.pop();
            if(visit[start]){
                continue;
            }
            visit[start] = true;
            for(int i=start+1;i<=s.size();i++){  //这里范围是[start,i)，左闭右开
                string prefix = s.substr(start,i-start);
                if(wordMap[prefix]){
                    if(i<s.size()){
                        q.push(i);
                    }else{
                        return true;
                    }
                }
            }
        }
        return false;  
    }
};

// 动态规划
// dp[i]代表长度为i的字符串，对应为[0,j-1]，表示这一段的子串是否能拆分成单词
class SolutionDp {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> wordMap;
        for(auto& word:wordDict){
            wordMap[word] = true;
        }
        int n = s.size();
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[i]==true) break;
                if(dp[j]==false){
                    continue;
                }
                string suffix = s.substr(j,i-j);
                if(wordMap[suffix] && dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];  
    }
};

// https://leetcode-cn.com/problems/word-break/solution/shou-hui-tu-jie-san-chong-fang-fa-dfs-bfs-dong-tai/