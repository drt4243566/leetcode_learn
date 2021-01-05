#include <iostream>
#include <vector>

using namespace std;

// 双指针解法，左右指针向中间遍历，遇到左指针为偶数，右指针为奇数的情况，swap两者；
// 终止条件是左指针>右指针（如果用!=判断，则会错过一些情况）
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

int main(){
    vector<int> nums = {1,2,3,4};
    Solution sol;
    vector<int> res = sol.exchange(nums);
    for(size_t i = 0;i!=res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}