class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n <= 3)
            return n - 1;
        if (n % 3 == 0)
            return pow(3, n / 3) % 1000000007;
        else if (n % 3 == 1)
            return (pow(3, n / 3 - 1) * 4) % 1000000007;
        else
            return (pow(3, n / 3) * 2) % 1000000007;

        // 错误示范： else return (int)(pow(3, n / 3) * 2) % 1000000007;
        // 这里不应该出现强制类型转换
        // 由于强制类型转换的优先级相当高，必须将整个表达式的值计算完成之后，进行取模，再转回int
    }

private:
    // 快速幂的技巧，奇数和偶数次幂不同 ，奇数单独多乘一次base，但是奇偶的除以2，直到1的次数理论上相同
    // 由于使用快速幂，所以res和base必须足够存放10000007^2的数字，所以选择long类型
    long pow(long base, int num)
    {
        long res = 1;
        while (num > 0)
        {
            if ((num & 1) == 1)  // 此时的num为奇数，相比于偶数次幂多乘1次base
            {
                res = (res * base) % 1000000007;
            }
            base = (base * base) % 1000000007;
            num >>= 1;
        }
        return res;
    }
};