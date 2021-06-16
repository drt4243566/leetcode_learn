#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n=0,k=0;
    cin >> n >> k;
    int x=0;
    vector<int> e0(32,0);
    for(int i=0;i<n;i++){
        cin >> x;
        int index=0;
        while(x){
            e0[index++] += x%k;
            x /= k;
        }
    }
    int res=0;
    for(int i=31;i>=0;i--){
        res = res*k+(e0[i]%k);
    }
    cout << res;
    return 0;
}