#include <iostream>
#include <vector>
using namespace std;

int judge(vector<int>& A,vector<int>& B){
    int res=0;
    int count=0;
    int NanShuang=0;
    int NvShuang=0;
    int HunShuang = 0;
    int sumA1=0,sumA2=0,sumB1=0,sumB2=0;
    for(int i=0;i<3;i++){
        sumA1 += A[i];
    }
    for(int i=3;i<6;i++){
        sumA2 += A[i];
    }
    for(int i=0;i<3;i++){
        sumB1 += B[i];
    }
    for(int i=3;i<6;i++){
        sumB2 += B[i];
    }

    /*cout << sumA1 << " ";
    cout << sumA2 << " ";
    cout << sumB1 << " ";
    cout << sumB2 << " ";*/

    for(int i=0;i<3;i++){
        for(int j=3;j<6;j++){
            for(int k=0;k<3;k++){
                for(int m=3;m<6;m++){
                    if(sumA1-A[i]>sumB1-B[k]) count++;
                    else count--;
                    if(sumA2-A[j]>sumB2-B[m]) count++;
                    else count--;
                    if(A[i]+A[j]>B[i]+B[j]) count++;
                    else count--;
                    if(count>0) res++;
                }
            }
        }
    }
    return count;
}

int main(){
    int T=0;
    cin >> T;
    int ans=0;
    while(T--){
        vector<int> A(6,0);
        vector<int> B(6,0);
        for(int i=0;i<6;i++){
            cin >> A[i];
        }
        for(int i=0;i<6;i++){
            cin >> B[i];
        }
        ans = judge(A,B);
        cout << ans <<endl;
    }
    return 0;
}