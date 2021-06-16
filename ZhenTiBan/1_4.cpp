// 最短子数组长度 -- 贪心

/*给定一个无序数组arr，求出需要排序的最短子数组的长度，对子数组排序后能使得整个数组有序，
即为需要排序的数组。例如：arr=[1,5,3,4,2,6,7]返回4，因为只有[5,3,4,2]需要排序。*/

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n=0;
    cin >> n;
    vector<int> nums(n,0);
    // 至少是要用到两个指针
    int p1=0,p2=0,pe=0;
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    for(int i=0;i<n;i++){
        if(nums[i]<nums[p1]) pe=i;
        else p1=i;
    }
    int temp = pe+1;
    p2 = pe+1;
    for(int i=p2;i>=0;i--){
        if(nums[i]>nums[p2]) pe=i;
        else p2=i;
    }
    cout << temp-pe;
    return 0;
}
