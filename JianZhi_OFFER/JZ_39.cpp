#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution1{
public:
    int majorityElement(vector<int> &nums){
        unordered_map<int,int> mp;
        for(int n:nums)
            if(++mp[n]>nums.size()/2) return n;
        return -1;
    }
};

// 哈希表方法
class Solution2{
public:
    int majorityElement(vector<int> &nums){
        unordered_map<int,int> mp;
        for(int n:nums)
            if(++mp[n]>nums.size()/2) return n;
        return -1;
    }
};

// 摩尔投票法
class Solution3{
public:
    int majorityElement(vector<int> &nums){
        int x=0,vote=0;
        for(int num:nums){
            // 每当票数归零，重新设定众数
            if(vote==0) x=num;
            vote += num==x?1:-1;
        }
        return x;
    }
};