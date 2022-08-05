#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target){
    int n = nums.size();
    int L = 0, R = nums.size();
    while(L<R){
        int mid = L + (R-L)/2;
        if(nums[mid]>target) R = mid;
        else if(nums[mid]<target) L = mid+1;
        else R = mid;
    }
    return nums[L]==target?L:-1;
}

int main(){
    return 0;
}