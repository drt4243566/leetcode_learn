#include <inttypes.h>
#include <stdint.h>
#include <cstdint>
#include <iostream>

using namespace std;

class Solution1
{
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;
        while(n>0){
            uint32_t pos = (~n + 1) & n;
            n = n-pos;
            count++;
        }
        return count;
    }
};

// 逐位判断法
class Solution2{
public:
    int hammingWeight(uint32_t n){
        int res = 0;
        while(n>0){
            // n&1==1 说明最后一位为1
            res += (n&1)?1:0;
            n >>= 1;
        }
        return res;
    }
};

// 巧用 n&(n-1) ，相当于消去最后一个1, 同时可以判断一个数是否是2的幂
class Solution3
{
public:
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        while (n > 0)
        {
            res++;
            n = n&(n-1);
        }
        return res;
    }
};

int main(){
    Solution3 sol1;
    uint32_t n;
    // 32位2进制数字输入方式较为特别
    scanf("%I32u",&n);
    // 实际输入的数字应当按照对应的十进制的int值来输入，（不能输入000000001001，而应该输入9）
    printf("%d\n",n);
    printf("%d\n",sol1.hammingWeight(n));
    // 在自己电脑输出的时候，总是将二进制数当成十进制数来进行计算
    return 0;
}