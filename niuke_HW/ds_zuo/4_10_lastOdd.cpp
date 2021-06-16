#include <iostream>

using namespace std;

class Solution{
public:
    int lastOdd(int n){
        int b = 1;
        while(b<n){
            b = b<<1;
        }
        return (b>>1)-1;
    }

};

int main(){
    int n;
    Solution s;
    while(cin>>n)
        cout<<s.lastOdd(n)<<endl;

    return 0;
}