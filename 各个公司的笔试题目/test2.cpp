#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> wordMap;
        //vector<int> mem(s.size(),0);
        for(auto& word:wordDict){
            wordMap[word] = true;
        }
        return canBreak(s,wordMap,0);
    }

    bool canBreak(string s,unordered_map<string,bool> &wordMap,int start){
        if(start==s.size()) return true;
        //if(mem[start]!=0){
        //    if(mem[start]>0) return true;
        //    else{
        //        return false;
        //    }
        //}
        for(int i=start+1;i<=s.size();i++){
            string prefix = s.substr(start,i-start);
            if(wordMap[prefix]&&canBreak(s,wordMap,i)){
                //mem[start] = 1;
                return true;
            }
        }
        //mem[start] = -1;
        return false;
    }
};

int main(){
    Solution sol;
    string s = "leetcode";
    vector<string> wordDict = {"leet","code"};
    cout << sol.wordBreak(s,wordDict)<<endl;
    return 0;
}