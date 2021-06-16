#include <iostream>
using namespace std;

/*接受0或者1，返回1或者0*/
int flip(int n) {
    return n^1;
}
/*n是非负数，返回1，n是负数，返回0*/
int sign(int n) {
    return flip(n >> 31) & 1;
}
int getMax1(int a, int b) {
    int c = a - b;
    int scA = sign(c);/* a-b为非负，scA为1；否则为0*/
    int scB = sign(scA);
    return a * scA + b * scB;
}
int getMax2(int a, int b) {
    int c = a - b;
    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);
    int difSab = sa ^ sb;
    int sameSab = flip(difSab);
    int returnA = difSab * sa + sameSab * sc;
    int returnB = flip(returnA);
    return a * returnA + b * returnB;
}
int main(){
    int a = -16;
    int b = 1;
    cout<<getMax1(a,b)<<" "<<getMax2(a,b)<<endl;
    a = 2147483647;
    b = -2147483647;
    cout<<getMax1(a,b)<<" "<<getMax2(a,b)<<endl;
    return 0;
}
