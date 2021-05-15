#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        // 使用哈希表保存单个字符出现的次数
        unordered_map<char,int> dic;
        // 记录出现的字符，并且去掉重复字符
        vector<char> keys;
        for(char c:s){
            if(dic.find(c)==dic.end()){
                keys.push_back(c);
            }
            dic[c]++;
        }
        // 此时遍历Vector，
        for(char c:keys){
            if(dic[c]==1) return c;
        }
        return ' ';
    }
};

// 哈希表直接储存bool类型，更加精简
class Solution2 {
public:
    char firstUniqChar(string s) {
        unordered_map<char,bool> dic;
        for(int i=0;i<s.size();i++){
            dic[s[i]] = dic.find(s[i])==dic.end();
        }
        for(char c:s){
            if(dic[c]) return c;
        }
        return ' ';
    }
};

int main(){
    Solution sol;
    string s = "1252144";
    char res = sol.firstUniqChar(s);
    return 0;
}