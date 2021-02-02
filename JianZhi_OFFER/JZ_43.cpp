#include <iostream>
#include <vector>
using namespace std;

// 传说中的数位DP问题
// 这道题主要还是找规律的板子
class Solution {
public:
    int countDigitOne(int n) {
        long digit=1,res=0;
        int high=n/10,cur=n%10,low=0;
        // 高位和当前位同时为0时，数字各位遍历完成
        // 主要判断每个位上可能为1的数量
        while(high!=0||cur!=0){
            if(cur==0) res += high*digit;
            else if(cur==1) res += high*digit+low+1;
            else res += (high+1)*digit;
            low += cur*digit;
            cur = high%10;
            high /= 10;
            digit *= 10;
        }
        return res;
    }
};