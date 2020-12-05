#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
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