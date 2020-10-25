#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // write code here
        int n = numbers.size();
        vector<int> res;
        unordered_map<int, int> mp; // key值代表numbers数组中的元素，value表示对应索引
        for (int i = 0; i < n; i++)
        {
            if (mp[target - numbers[i]] != 0)
            {
                res.push_back(mp[target - numbers[i]]); // 这里的次序，由于匹配的是先前存入的元素
                res.push_back(i + 1);                   // 所以匹配项存在前面
                break;
            }
            else
            {
                mp[numbers[i]] = i + 1; // 索引从1开始计算，因此需要+1
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> numbers = {3, 2, 4};
    int target = 6;
    vector<int> res = sol.twoSum(numbers, target);
    for (int i : res)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}