#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 使用深度优先搜索的思路
class Solution {
    vector<string> res;
    vector<char> c_char;
public:
    vector<string> permutation(string s) {
        for(int i=0;i<s.size();i++){
            c_char.push_back(s[i]);
        }
        dfs(0);
        return res;
    }
    void dfs(int x){
        if(x==c_char.size()-1){
            string list(c_char.begin(),c_char.end());
            res.push_back(list);
            return;
        }
        // 防止同一个位置的递归出现重复的情况
        unordered_set<char> st;
        for(int i=x;i<c_char.size();++i){
            if(st.count(c_char[i])) continue;
            st.insert(c_char[i]);
            // 这一手交换是战术核心，依次固定了每个位置上的字符，并且通过交换的方式，确保单个不重复
            swap(c_char[i],c_char[x]);
            dfs(x+1);
            swap(c_char[i],c_char[x]);
        }
    }
};

class Solution {
public:
    vector<string> permutation(string s) {
        dfs(s, 0);
        return res;
    }
private:
    vector<string> res;
    void dfs(string s, int x) {
        if(x == s.size() - 1) {
            res.push_back(s);                       // 添加排列方案
            return;
        }
        unordered_set<int> st;
        for(int i = x; i < s.size(); i++) {
            if(st.find(s[i]) != st.end()) continue; // 重复，因此剪枝
            st.insert(s[i]);
            swap(s[i], s[x]);                       // 交换，将 s[i] 固定在第 x 位
            dfs(s, x + 1);                          // 开启固定第 x + 1 位字符
            swap(s[i], s[x]);                       // 恢复交换
        }
    }
};
