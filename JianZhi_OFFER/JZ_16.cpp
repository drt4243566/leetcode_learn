// 直接循环导致超时，也就是O(n)时间复杂度
class Solution
{
public:
    double myPow(double x, int n)
    {
        double res = 1;
        while(n>0){
            res *= x;
            n--;
        }
        while(n<0){
            res /= x;
            n++;
        }
        return res;
    }
};

class Solution1
{
public:
    // 题目存在一个很坑的设定 int32 变量对应的数字范围是[-2147483648,2147483647],所以不能直接取-n，转为long类型计算
    double myPow(double x, int n)
    {
        if(x==0) return 0;
        long b=n;
        double res =1;
        // 负幂的转换
        if(b<0){
            x = 1/x;
            b = -b;
        }
        while(b>0){
            if(b&1==1) res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
    }
};

