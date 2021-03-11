#include <vector>
using namespace std;

// 经典对撞双指针，画出所有可能的表时，从右上角的顶点处开始遍历
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<j){
            int s = nums[i]+nums[j];
            if(s==target) return vector<int>{nums[i],nums[j]};
            else if(s<target) i++;
            else j--;
        }
        return {0,0};
    }
};