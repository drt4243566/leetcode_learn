#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int isprime(int sum){
    if(sum<2){
        return 0;
    }
    if(sum==2){
        return 1;
    }
    for(int i=2;i<=int(sqrt(sum));i++){
        if(sum%i==0){
            return 0;
        }
    }
    return 1;
}
int process(vector<int> v, int n, int k, int index, int sum){
    if(k==0){
        if(isprime(sum)){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(index>n){
        return 0;
    }
    return process(v,n,k,index+1,sum) + process(v,n,k-1,index+1,sum+v[index]);
}
int main(){
    int n;
    int k;
    while(cin>>n>>k){
        vector<int> v(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }
        int res = process(v,n,k,1,0);
        cout<<res<<endl;
    }
    return 0;
}
