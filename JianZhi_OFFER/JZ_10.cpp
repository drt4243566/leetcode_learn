// 斐波那契数列的问题
class Solution
{
public:
    /*int fib(int n) {
        if(n==0) return 0;
        else if(n==1) return 1;
        int res = fib(n-1) + fib(n-2);
        return res;
    }*/
    // 递归法显然不行，日常超时

    // 非递归实现
    int fib(int n)
    {
        if (n == 0 || n == 1)
            return n;
        // a在前，b在后，用这两个变量轮番推进, 单次循环只会向前推进一位
        // 有尝试的意味，f(2)=1+0=1，循环需要执行一次；f(3)要执行两次
        int a = 1, b = 0;
        for (int i = 1; i < n; i++)
        {
            // 下面两句精髓
            a += b;
            b = a - b;
            a %= 1000000007;
        }
        return a;
    }
};