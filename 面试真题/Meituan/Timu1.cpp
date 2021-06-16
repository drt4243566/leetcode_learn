#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    /**
     * 
     * @param str string字符串 the string
     * @return string字符串
     */
    string changeString(string str) {
        // write code here
        unordered_map<char,int> mp;
        string temp;
        for(int i=0;i<str.size();i++){
            if(mp.count(str[i])!=0){
                mp[str[i]]++;
            }
            else{
                mp[str[i]] = 1;
                temp.push_back(str[i]);
            }
        }
        string res;
        for(char c:temp){
            res.push_back(c);
            res.push_back('_');
            string t;
            res = res + to_string(mp[c]);
            res.push_back('_');
        }
        res.erase(res.end()-1);
        return res;
    }
};

char getCharAt(string str,int index){
    int num=0;
    int sum=0;
    bool flag = true;
    char cur;
    for(int i=0;i<str.size();i++){
        if(str[i]=='_') flag = !flag;
        else if(flag){
            sum += num;
            // 和序列的标识有关
            if(sum>index) return cur;
            cur = str[i];
            num = 0;
        }
        else{
            num = num*10+str[i]-'0';
        }
    }
    return sum+num>index?cur:0;
} 

int main(){
    Solution sol1;
    string str = "offerofferzainaliiiiii";
    string res = sol1.changeString(str);
    cout << res << endl;
}