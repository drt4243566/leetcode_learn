#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 滑动窗口
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0||n==1) return n;
        unordered_set<char> set;
        int L=0;
        int Max=0;
        for(int i=0;i<n;i++){
            while(set.find(s[i])!=set.end()){
                // 每次抛出Set最左边的元素
                set.erase(s[L++]);
            }
            Max = max(Max,i-L+1);
            set.insert(s[i]);
        }
        return Max;
    }
};


// 动态规划
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int res = 0,tmp = 0;
        for(int j=0;j<s.size();j++){
            int i=-1;
            if(mp.find(s[j])!=mp.end()) i = mp[s[j]];
            mp[s[j]] = j;
            tmp = tmp<j-i?tmp+1:j-i;
            res = max(res,tmp);
        }
        return res;
    }
};
