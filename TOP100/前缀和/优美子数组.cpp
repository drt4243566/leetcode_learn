#include <iostream>
#include <vector>
using namespace std;

// 滑动窗口法
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left=0,right=0,oddCnt=0;
        int res=0;
        while(right<nums.size()){
            if((nums[right++]&1)==1){
                oddCnt++;
            }
            if(oddCnt==k){
                int tmp = right;
                while(right<nums.size()&&(nums[right]&1)==0){
                    right++;
                }
                int rightEvenCnt = right-tmp;
                int leftEvenCnt=0;
                while((nums[left]&1)==0){
                    left++;
                    leftEvenCnt++;
                }
                res += (leftEvenCnt+1)*(rightEvenCnt+1);

                left++;
                oddCnt--;
            }
        }
        return res;
    }
};

// 前缀和，所以pre[j-1]==pre[i]-k，这里指的就是[j,i]这个子数组里的奇数个数正好为k
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> pre(nums.size()+1,0);
        // 在使用前缀和的时候，还有不包括使用前缀的情况，多一种可能性
        pre[0] = 1;
        int res=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i]&1;
            pre[sum]++;
            if(sum>=k){
                res+=pre[sum-k];
            }
        }
        return res;
    }
};