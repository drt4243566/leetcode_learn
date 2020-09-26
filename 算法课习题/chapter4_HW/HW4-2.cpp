#include<unordered_map>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        int n = numbers.size();
        vector<int> res;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp[target - numbers[i]] != 0) {
                res.push_back(mp[target - numbers[i]]);
                res.push_back(i + 1);
                break;
            }
            else {
                mp[numbers[i]] = i + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {3,2,4};
    int target=6;
   vector<int> res = sol.twoSum(numbers, target);
   for (int i : res) {
       cout << i << " ";
   }
    cout << endl;
	return 0;
}