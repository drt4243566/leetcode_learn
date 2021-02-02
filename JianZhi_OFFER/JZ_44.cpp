#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int findNthDigit(int n) {
        int digit=1;
        long start=1,count=9;
        while(n>count){
            n -= count;
            digit++;
            start *= 10;
            count = digit*start*9;
        }
        // 从start开始推算num，举个例子，如果num=10，在第一步减去count=9之后，
        // 还剩下的n为0或1，即为(n-1)/digit
        long num = start+(n-1)/digit;
        //确定所求数位在num里的哪一位？ ——调用取数字里某一位的函数 or 把数字转换为str
        string s = to_string(num);
        int res = s[(n-1)%digit]-'0';   //自动将char类型转换为int，但要注意减去'0'
        return res;
    }
};

int main(){
    Solution sol1;
    int res = sol1.findNthDigit(11);
    return 0;
}