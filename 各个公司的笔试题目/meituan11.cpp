#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
    }

    int L=1,R=N-2;
    int sum=0;

    while(L<R){
        if(nums[L]<nums[L-1]){
            sum += nums[L-1]-nums[L]+1;
        }
        L++;
        if(nums[R]<nums[R+1]){
            sum += nums[R+1]-nums[R]+1;
        }
        R--;
        if((R-L==1) && nums[R]==nums[L]){
            sum++;
            break;
        }
    }
    int flag=0;
    if(L==R){
        flag = max(max(nums[L-1]-nums[L]+1,nums[R+1]-nums[R]+1),0);
        sum += flag;
    }
    cout << sum <<endl;
    return 0;
}