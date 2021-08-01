#include <math.h>
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        if(n<1) return 0;
        int len = getNumLen(n);
        if(len<2) return 1;
        int temp = pow(10,len-1);
        // 首位数字
        int first = n/temp;
        int firstNum = first==1?n%temp+1:temp;
        int otherNum = first*(temp/10)*(len-1);
        return firstNum+otherNum+NumberOf1Between1AndN_Solution(n%temp);
    }
    
    int getNumLen(int num){
        int len=0;
        while(num>0){
            num /= 10;
            len++;
        }
        return len;
    }
};