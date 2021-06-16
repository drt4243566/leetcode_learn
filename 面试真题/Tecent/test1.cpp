#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n,0);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    int res=0;
    for(int i=0;i<n;i++){
        int count = 1;
        int left=0,right=0;
        for(int j=i-1;j>=0;j--){
            if(A[j]<A[j+1]) {
                count++;
                left = 1;
            }
            else
                break;
        }
        for(int k=i+1;k<n;k++){
            if(A[k]<A[k-1]){
                count++;
                right = 1;
            }
            else{
                break;
            }
        }
        if(count>=3&&left&&right){
            res = max(res,count);
        }
    }
    cout << res;
    return 0;
}