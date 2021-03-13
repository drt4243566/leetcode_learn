#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
// 判断5张牌是不是连续有个简便的方式 —— 5张牌里面最大的牌为max，最小的牌为min，则max-min<5,而且除了大小王之外没有重复牌;
// 集合set判别是否重复+遍历
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        // 用于判断重复牌
        unordered_set<int> Hashset;
        int maxNum=0,minNum=14;
        for(int num:nums){
            // 大小王直接跳过
            if(num==0) continue;
            // 更新最大最小值
            maxNum = max(maxNum,num);
            minNum = min(minNum,num);
            if(Hashset.find(num)!=Hashset.end()) return false;
            Hashset.insert(num);
        }
        return (maxNum-minNum)<5;
    }
};

// 先对数组排序+遍历
class Solution1 {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int joker=0;
        for(int i=0;i<5;i++){
            // 记录大小王的个数
            if(nums[i]==0) joker++;
            // 判断是否存在重复牌（除了大小王之外）
            else if(i!=4&&nums[i]==nums[i+1]) return false;
        }
        return nums[4]-nums[joker]<5;
    }
};

int main(){
    vector<int> 
}