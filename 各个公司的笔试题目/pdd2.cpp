#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int howManyWei(int num){
    int res = 0;
    while(num>0){
        num /= 10;
        res++;
    }
    return res;
}

int judgeMin(int N,int M){
    long res = -1;
    double PowerMin = pow(10,N-1);
    int WeiNum = howManyWei(M);
    int factor = PowerMin/M;
    long factorRes=0;
    while(WeiNum<=N){
        if(WeiNum==N){
            res = factorRes;
            break;
        }
        factorRes = M*factor;
        factor++;
        WeiNum = howManyWei(factorRes);
    }
    return res;
}

int main(){
    int T = 0;
    cin >> T;
    while(T--){
        int N=0,M=0;
        cin >> N >> M;
        int res = 0;
        res = judgeMin(N,M);
        cout << res << endl;
    }
    return 0;
}