#include <iostream>
#include <vector>
using namespace std;

/* i+1是因为0这个位置被初始状态给占了，所以后面的状态位置都得往后移一位。
而初始状态就是还没统计任何字符时的状态，即status=0，设置的初始状态的位置
为0，即pos[status]=0。而不把这个初始状态位置设为-1的原因是-1被用作判断是
否为第一次出现的特殊用途了。 */

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0, status = 0, n = s.size();
        vector<int> pos(1 << 5, -1);
        // 初始状态，即还未统计任何字符时的状态
        pos[0] = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                status ^= 1<<0;
            } else if (s[i] == 'e') {
                status ^= 1<<1;
            } else if (s[i] == 'i') {
                status ^= 1<<2;
            } else if (s[i] == 'o') {
                status ^= 1<<3;
            } else if (s[i] == 'u') {
                status ^= 1<<4;
            }
            // 直接判断pos[status]>=0等同
            // 深究下去是初始位置为0，但是在计算子串的长度的时候，差值+1，而由于直接记录的是i+1，因此ok
            if (~pos[status]) {
                ans = max(ans, i + 1 - pos[status]);
            } else {
                pos[status] = i + 1;
            }
        }
        return ans;
    }
};