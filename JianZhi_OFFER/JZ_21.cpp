#include <iostream>
#include <vector>

using namespace std;

// 首尾双指针解法，左右指针向中间遍历，遇到左指针为偶数，右指针为奇数的情况，swap两者；
// 终止条件是左指针>=右指针（如果用==判断，则会错过一些情况）
class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int i=0, j=nums.size()-1;
        while(i<j){
            if((nums[i]&1) == 1){  // 左侧正向遍历的指针i,奇数不交换
                i++;
                continue;
            }
            else if ((nums[j]&1) == 0){ //从右侧反向遍历的指针j，偶数不交换
                j--;
                continue;
            }
            int temp = nums[i];
            nums[i++] = nums[j];
            nums[j--] = temp;
        }
        return nums;
    }
};

// 快慢双指针解法
// 快指针向前搜索奇数，慢指针用于存放下一个奇数存储的位置
// 快慢指针的方式性能较差，如果连续奇数，快指针失去作用，多次执行原地交换
class Solution2{
public:
    vector<int> exchange(vector<int> &nums){
        int fast=0 ,slow = 0;
        while(fast<nums.size()){
            if((nums[fast]&1)==1){
                int temp = nums[fast];
                nums[fast] = nums[slow];
                nums[slow] = temp;
                slow++;
            }
            fast++;
        }
        return nums;
    }
};

int main(){
    vector<int> nums = {2,5,3,7,8};
    Solution sol;
    Solution2 sol2;
    vector<int> res = sol2.exchange(nums);
    for(size_t i = 0;i!=res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}