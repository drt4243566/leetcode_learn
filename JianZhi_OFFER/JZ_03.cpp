#include <iostream>
#include <vector>

using namespace std;

// 空间复杂度最小 -- 原地置换法
class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        // 整体思路是在i位置上放置元素i，正常排序成功后，数字i就应当在下标i的位置
        // 扫描数组，当遇到下标为i的数如果不是i的话，拿它和下标为nums[i]的数字交换；
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i)
            {
                if (nums[nums[i]] == nums[i])
                    return nums[i];
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;           // 重点在这一步的下标必须要用tmp
                /*int tmp = nums[i];
                nums[i] = nums[nums[i]];   // 这一步将nums[i]已经改变
                nums[nums[i]] = tmp;*/
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> data={2,3,1,0,2,5,3};
    int res=sol.findRepeatNumber(data);
    cout<<res<<endl;
    return 0;
}
// RE 鸽巢原理，使用的前提是所有的数字都在[0,n-1]范围内，否则只能哈希表
int findRepeatNumber(vector<int> &nums){
    for(int i=0;i<nums.size();i++){
        while(nums[i]!=i){
            if(nums[i]==nums[nums[i]]){
                return nums[i];
            }
            int temp = nums[i];
            nums[i] = nums[temp];
            nums[temp] = temp;           
        }
    }
}