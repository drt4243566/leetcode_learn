#include <iostream>
using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
    int Fibonacci2(int n) {
        int a=0,b=1,c=1;
        for(int i=1;i<=n;i++){
            c=a+b;
            a=b;b=c;
        }
        return a;
    }
};

int main()
{
    Solution s;
    cout<<s.Fibonacci2(2)<<endl;

    return 0;
}