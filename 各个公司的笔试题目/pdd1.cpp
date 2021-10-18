#include <iostream>
#include <vector>
using namespace std;

int calpq(int p,int q){
    int res = 0;
    if(p>q){
        if((p-q)%2==0){
            return (p-q)/2;
        }else{
            return (p-q)/2+1;
        }
    }else if(p<q){
        if(q-p==1) return 1;
        if(q%2==0){
            res = min(calpq(p,q/2)+1,q-p);
        }else{
            res = min(calpq(p,(q-1)/2),calpq(p,(q+1)/2))+2;
            res = min(res,q-p);
        }
    }else{
        return 0;
    }
    return res;
}

int main(){
    int T = 0;
    cin >> T;
    while(T--){
        int P=0,Q=0;
        cin >> P >> Q;
        int res = 0;
        res = calpq(P,Q);
        cout << res << endl;
    }
    return 0;
}

/*
10 15  （14，16）

p<q
1.全靠多云，q-p
2.找到q最近的偶数 (q偶数|q为奇数（q-1和q+1）),取对半

p>q
往下减 这个步数 偶数：(p-q)/2 奇数：(p-q)/2+1
*/