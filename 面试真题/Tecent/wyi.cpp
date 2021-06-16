#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubStrLength(vector<char>& charList, string s) {
        // write code here
        int L=0,R=0;
        int MaxLen=0;
        unordered_map<char,int> mp;
        for(int i=0;i<charList.size();i++){
            mp[charList[i]] = 0;
        }
        int n = s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<charList.size();j++){
                if(charList[j]==s[i]){
                    mp[charList[j]]++;
                    break;
                }

            }
        }
    }
};

int main(){
    Solution sol;

    return 0;
}