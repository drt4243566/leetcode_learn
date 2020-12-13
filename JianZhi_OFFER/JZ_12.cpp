#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(DFS(board,word,i,j,0)) return true;
            }
        }
        return false;
    }

    // 递归实现的DFS，i和j代表目前所在的位置坐标，k表示目前匹配到的字符串的位置（word.size()-1结束）
    bool DFS(vector<vector<char>> &board, string word,int i,int j,int k){
        int rows = board.size();
        int cols = board[0].size();

        if(i<0||i>=rows||j<0||j>=cols||board[i][j]!=word[k]) return false;  //判断越界在前，再判断是否匹配字符串

        int kWord = word.size()-1;
        if(k==kWord) return true;

        board[i][j] = '\0';      // 标记已经搜索过的位置

        bool res = DFS(board, word, i + 1, j, k + 1) || DFS(board, word, i - 1, j, k + 1) || DFS(board, word, i, j + 1, k + 1) || DFS(board, word, i, j - 1, k + 1);

        board[i][j] = word[k];   // 结束后回溯过程复原原本的值

        return res;
    }
};
