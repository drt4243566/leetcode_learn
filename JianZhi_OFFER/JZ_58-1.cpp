#include <iostream>
#include <string>
using namespace std;

// 经典双指针，从后往前遍历，分别指向每个单词的左右边界处，右指针指向
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int n=s.size();
        if(n==0) return res;
        int right = n-1;
        while(right>=0){
            // 从后往前寻找第一个字符
            while(right>=0&&s[right]==' ') right--;
            if(right<0) break;
            // 寻找此单词的左边界，停在空格字符的位置
            int left=right;
            while(left>=0&&s[left]!=' ') left--;
            // 添加单词到结果
            res.append(s.substr(left+1,right-left));
            res.append(" ");
            // 继续向前分割
            right = left;
        }
        // 去掉最后一个字符空格
        if(!res.empty()) res.pop_back();
        return res;
    }
};