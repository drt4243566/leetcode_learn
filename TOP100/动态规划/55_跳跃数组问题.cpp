#include <vector>
using namespace std;

// 已知一定能跳到数组末尾，问最少需要跳几步
int jump_arr(vector<int>& nums){
    int n = nums.size();
    int step = 0;
    int curR = 0,nextR=0;
    for(int i=0;i<n;i++){
        if(i>curR){
            curR = nextR;
            step++;
        }
        nextR = max(nextR,i+nums[i]);
    }
    return step;
}

// 如果问的是究竟能否到达数组末尾，思路是只管推进nextR即可
bool canJump(vector<int>& nums){
    int n = nums.size();
    int nextR = 0;
    for(int i=0;i<n;i++){
        if(i>nextR) return false;
        nextR = max(nextR,i+nums[i]);
    }
    return true;
}