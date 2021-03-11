#include <iostream>
#include <vector>
using namespace std;

// 前置知识点：如果数组当中其他数字都出现2次，只有一个数字出现1次的时候，只要让全部的数字都进行一轮异或即可；
// 当有两个数字出现1次的时候，思路是进行分组： 1.两个独特的数字分成不同的组；2.相同的数字分成相同的组；
// 继续进行全部数字的异或，结果是a和b的异或值，记录为x，则将x写成2进制数，其中某一位xi;
// 如果xi=0表明此位ai=bi，反之xi=1则表明两者不等；任取一个不为0的xi，按照第i位给原来的序列进行分组即可；
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret=0;
        for(int n:nums) ret^=n;
        int div = 1;
        // 寻找不为0的最低位
        // 注意这里的优先级问题
        while((div&ret)==0)
            div <<= 1;
        int a=0,b=0;
        for(int n:nums){
            // 只要不为0就表示在同一组
            if(n&div){
                a^=n;
            }
            else
                b^=n;
        }
        return vector<int>{a,b};
    }
};