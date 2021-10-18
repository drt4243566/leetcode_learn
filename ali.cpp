#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

long reverse(long x,int k){
    if(x==1){
        return 1;
    }
    int res=0;
    vector<int> nums;
    while(x>0){
        int num = x%k;
        nums.push_back(num);
        x /= k;
    }
    for(int i=0;i<nums.size();i++){
        res = res*k + nums[i];
    }
    return res;
}

int main(){
    int t=0;
    cin >> t;
    long res = 0;
    while(t--){
        long n=0;
        int k=0;
        cin >> n >> k;
        res = reverse(n,k);
        cout << res << endl;
    }
    return 0;
}