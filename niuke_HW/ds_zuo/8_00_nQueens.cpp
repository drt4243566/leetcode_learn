#include <iostream>
using namespace std;
int process2(int mask,int colMask, int lefDiaMask, int rigDiaMask){
    if(colMask == mask){
        return 1;
    }
    int pos = mask & (~(colMask | lefDiaMask | rigDiaMask));
    int mostRightOne = 0;
    int res = 0;
    while(pos != 0){
        mostRightOne = pos & (~pos + 1);
        pos = pos - mostRightOne;
        res += process2(mask,colMask | mostRightOne,
                        (lefDiaMask | mostRightOne)<<1,
                        (rigDiaMask | mostRightOne)>>1);
    }
    return res;
}
int nQueens2(int N){
    if(N<1 or N>32){
        return 0;
    }
    int mask = N==32?-1:(1<<N)-1;
    return process2(mask,0,0,0);
}
int main(){
    cout<<nQueens2(16);
    return 0;
}
