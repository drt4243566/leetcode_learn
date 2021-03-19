#include <iostream>
using namespace std;
class Solution {
// 经典位运算
// 模拟加法 -- 无进位的加法=异或运算，进位==与运算，进位左移一位后叠加再原先数字上即可
// 但是c++不支持带符号的左移，需要先转换为无符号数
public:
    int add(int a, int b) {
        while(b!=0){
            // c为进位
            int c=(unsigned int)(a&b)<<1; 
            // a保存着非进位和
            a = a^b;
            b = c;
        }
        return a;
    }
};

int main(){
    int a = -100;
    cout<<a<<" ";
    int b = (unsigned int)a;
    cout<<b; 
}