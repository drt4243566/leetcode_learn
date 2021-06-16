#include <iostream>
using namespace std;
int Plus(int a, int b) {
    int sum = a;
    while(b != 0) {
        sum = a ^ b;
        b = (a & b) << 1;
        a = sum;
    }
    return sum;
}
int negNum(int n) {
    return Plus(~n, 1);
}
int Minus(int a, int b) {
    return Plus(a, negNum(b));
}
int Multi(int a, int b) {
    int res = 0;
    while(b != 0) {
        if((b & 1) != 0) {
            res = Plus(res, a);
        }
        a <<= 1;
        b = (unsigned)b >> 1;
    }
    return res;
}
bool isNeg(int n) {
    return n < 0;
}
int Div(int a, int b) {
    int x = isNeg(a) ? negNum(a) : a;
    int y = isNeg(b) ? negNum(b) : b;
    int res = 0;
    for(int i=31;i>-1;i=Minus(i,1)) {
        if((x>>i) >= y) {
            res |= (1<<i);
            x = Minus(x,y<<i);
        }
    }
    return isNeg(a) ^ isNeg(b) ? negNum(res):res;
}
int Divide(int a, int b) {
    if( b==0) {
        throw runtime_error("divisor is 0");
    }
    if(a==INT_MIN && b==INT_MIN){
        return 1;
    }else if(b==INT_MIN){
        return 0;
    }else if(a==INT_MIN) {
        int res = Div(Plus(a,1),b);
        return Plus(res,Div(Minus(a,Multi(res,b)),b));
    }else{
        return Div(a,b);
    }
}
int main(){
    cout<<Plus(12,45)<<endl;
    cout<<Minus(12,45)<<endl;
    cout<<Multi(12,-3)<<endl;
    cout<<Divide(12,-3)<<endl;
    return 0;
}
