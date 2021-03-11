#include <vector>
using namespace std;

// 有序数组的搜索问题，首先就要想到使用二分法查找，或者是双指针法
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i=0, j=nums.size()-1;
        // 搜索区间无元素时跳出循环
        while(i<=j){
            int mid = i+(j-i)/2;
            if(nums[mid]==mid) i=mid+1;
            else j=mid-1;
        }
        // 要考虑当搜索区间只剩下一个元素时，必然是要寻找的右边界，所以循环跳出时，i为右子数组的首个元素,j为左子数组的末位元素
        return i;
    }
};