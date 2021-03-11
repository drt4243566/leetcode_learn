#include <vector>
using namespace std;
// 复杂版本的二分法
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        // 有效查找区间范围是 [i,j] ，跳出条件为查找范围不存在任何数字，i=j+1;
        while(i<=j){
            int m = i+(j-i)/2;
            if(nums[m]<target) i=m+1;
            else if(nums[m]>target) j=m-1;
            // 若nums[i]正好等于target，先查找右边界
            else{
                i = m+1;
            }
        }
        int right = i;
        // 当i为右边界时，如果此时j处不为target可以直接返回0
        if(j>=0 && nums[j]!=target) return 0;
        // 搜索左边界
        i=0;
        j=nums.size()-1;
        while(i<=j){
            int m = i+(j-i)/2;
            if(nums[m]>=target) j=m-1;
            else i = m+1;
        }
        int left = j;
        return right-left-1;
    }
};

// 精简版本二分法，利用有序数组，分别查找target的右边界和target-1的右边界
class Solution2{
public:
    int search(vector<int>& nums, int target) {
        return helper(nums,target)-helper(nums,target-1);
    }
    int helper(vector<int>& nums, int target){
        int i=0, j=nums.size()-1;
        while(i<=j){
            int m = i+(j-i)/2;
            if(nums[m]<=target) i=m+1;
            else j = m-1;
        }
        return i;
    }
};