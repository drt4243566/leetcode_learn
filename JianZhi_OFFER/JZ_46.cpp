#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 经典动态规划
class Solution1 {
public:
    int translateNum(int num) {
        string str = to_string(num);
        // dp[1]和dp[0]的初始值为1(由于dp[2]明显为2，当处于规定[10-25]的范围内时；00-09无法翻译，大于26的没有对应字母)
        // 依然是xi左侧的字符串，结果还是dp[n]
        int a=1,b=1;
        // 每次考虑连续两个字符是否能被直接翻译？从i-2开始遍历，最后到str.size()结束
        for(int i=2;i<=str.size();i++){
            string temp = str.substr(i-2,2);
            int c = (temp>="10")&&(temp<="25")?a+b:a;
            // a代表i-1，b代表i-2，对其更新
            b=a;
            a=c;
        }
        return a;
    }
};

// 利用问题的对称性，将从左往右的问题化为从右往左的等价问题
class Solution2{
public:
    int translateNum(int num){
        int a=1,b=1,x=0,y=num%10;
        while(num!=0){
            num=num/10;
            x=num%10;
            // 必须以每两位数字作为判断条件
            int temp = 10*x+y;
            int c = (temp>=10)&&(temp<=25)?a+b:a;
            b=a;
            a=c;
            y=x;
        }
        return a;
    }
};