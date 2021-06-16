// 3.无重复字符的最长子串

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int left=0;
       int res=0;
       unordered_set<char> set;
       for(int i=0;i<s.size();i++){
           while(set.find(s[i])!=set.end()){
               set.erase(s[left]);
               left++;
           }
           res = max(res,i-left+1);
           set.insert(s[i]);
       }
       return res;
    }
};