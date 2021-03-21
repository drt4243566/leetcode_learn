#include <iostream>
#include <vector>
using namespace std;
int process1(vector<int> arr, int index, int rest) {
    if(rest < 0) {
        return -1;
    }
    if(rest == 0){
        return 0;
    }
    if(index == arr.size()){
        return -1;
    }
    int p1 = process1(arr, index+1, rest);
    int p2Next = process1(arr, index+1, rest-arr[index]);
    if((p1 == -1) && (p2Next == -1)) {
        return -1;
    } else {
        if(p1 == -1) {
            return p2Next + 1;
        }
        if(p2Next == -1) {
            return p1;
        }
        return min(p1, p2Next + 1);
    }
}
int minCoins1(vector<int> arr, int aim) {
    return process1(arr, 0, aim);
}
int main(){
    /*每种硬币只用一次，能够凑出aim的最少硬币数量*/
    vector<int> arr{1,2,3,4,5,6,7,8,9,10};
    cout<<minCoins1(arr,20)<<endl;
    return 0;
}
