#include <vector>
using namespace std;
// 解题原则是将数字都用二进制表示之后，单看某一位，累加的结果对3取余数，只剩下只出现一次的数字的位
// 神仙解法 -- 有限状态机
// 只用00，01，10三种状态（two,one）表示单个数据位上的状态；在遍历结束后，必然是在00和01状态中的一个，这个由one来记录;
// 创建int类型的ones和twos，相当于在32位上进行相同的操作，一步到位；
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twos=0;
        for(int n:nums){
            ones = ones^n&~twos;
            twos = twos^n&~ones;
        }
        return ones;
    }
};

// 另一种思路 ———— 选择用长度位32的数组来记录每位上累加的结果，最后取余
class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> counts(32,0);
        for(int n:nums){
            for(int j=0;j<32;j++){
                counts[j] += n&1;
                n >>= 1;
            }
        }
        // 复原要找的数字，每次先左移一位，再进行或操作
        int res=0,m=3;
        for(int i=0;i<32;i++){
            res<<=1;
            res|=counts[31-i]%m;
        }
        return res;
    }
};