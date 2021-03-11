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
        for(auto str:strs){
            res += str;
        }
        return res;
    }
    // 可以理解为当return为true时，a放在b的前面
    // 这里的static必须加，由于类中的成员函数调用时存在隐藏参数*this(implicit parameter)，
    // 所以无法调用，添加static即可
    static bool compare(const string &a,const string &b){
        return a+b<b+a;
    }
};