#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// 动态规划解法
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> dic;
        int res=0,temp=0;
        for(int j=0;j<s.size();j++){
            int i = dic.count(s[j])?dic[s[j]]:-1;
            dic[s[j]]=j;
            temp = temp<j-i?temp+1:j-i;
            res = max(res,temp);
        }
        return res;
    }
};

// 滑动窗口
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        // 滑动窗口为：(start,i] 左开右闭，初值-1
        int res=0,start=-1;
        // 哈希表统计各字符最后出现的位置
        unordered_map<char,int> dic;
        for(int i=0;i<s.size();i++){
            char tmp = s[i];
            // 当字符在hash表中已经储存时，要判断index和start的大小，来确保更新(index是tmp对应的索引)
            // 当index>start时，start更新为当前的index（不重复子串的长度减小）
            if(dic.find(tmp)!=dic.end()){
                start = max(start,dic[tmp]);
            }
            // 更新哈希表中当前索引
            dic[tmp] = i;
            res = max(res,i-start);
        }
        return res;
    }
}；
