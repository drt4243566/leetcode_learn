#include <iostream>
using namespace std;
inline long read(){
    long x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int main(){
    int T;
    cin >> T;
    long L;
    long R;
    long a;
    long ans;
    while(T-- > 0) {
        L = read();
        R = read();
        a = L ^ R;
        ans = 0;
        while(a!=0) {
            ans = (ans << 1) | 1;
            a >>= 1;
        }
        cout << ans <<endl;
    }
    return 0;
}
