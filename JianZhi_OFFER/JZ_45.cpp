#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(int num:nums){
            strs.push_back(to_string(num));
        }
        sort(strs.begin(),strs.end(),compare);
    }
private:
    // 可以理解为当return为true时，a放在b的前面
    bool compare(const string &a,const string &b){
        return a+b<b+a;
    }
};