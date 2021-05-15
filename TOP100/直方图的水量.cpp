#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

// 朴素解法
class Solution1{
public:
    int trap(vector<int>& height){
        int n = height.size();
        int ans=0;
        for(int cur=1;cur<n-1;cur++){
            int L_high=0,R_high=0;
            for(int i=cur;i>=0;i--) L_high = max(L_high,height[cur]);
            for(int j=cur;j<n;j++) R_high = max(R_high,height[cur]);
            ans += min(L_high,R_high)-height[cur];
        }
    }
};

// 预处理解法，有点动态规划的意思，依次遍历，找到每个位置而言左侧和右侧所有元素的最大值；
class Solution{
public:
    int trap(vector<int>& height){
        int n = height.size();
        int res = 0;
        vector<int> fMax(n,0),gMax(n,0);
        fMax[0] = height[0];
        gMax[n-1] = height[n-1];
        for(int i=1;i<n;i++){
            fMax[i] = max(fMax[i-1],height[i]);
        }
        for(int j=n-2;j>=0;j--){
            gMax[j] = max(gMax[j+1],height[j]);
        }
        for(int i=0;i<n;i++){
            res += min(fMax[i],gMax[i])-height[i];
        }
        return res;
    }
};

// 单调栈解法
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int res=0;
        int n = height.size();
        for(int i=0;i<n;i++){
            while(!st.empty()&&height[st.top()]<height[i]){
                int cur = st.top();
                st.pop();
                if(!st.empty()) res += (i-st.top()-1)*(min(height[i],height[st.top()])-height[cur]);
            }
            st.push(i);
        }
        return res;
    }
};

// 双指针法
class Solution {
public:
    int trap(vector<int>& height) {
        // 总降水量
        int sum = accumulate(height.begin(),height.end(),0);
        int valume = 0;
        int level = 1;
        int L=0,R=height.size()-1;
        while(L<=R){
            while(L<=R&&height[L]<level){
                L++;
            }
            while(L<=R&&height[R]<level){
                R--;
            }
            valume += R-L+1;
            level++;
        }
        return valume-sum;
    }
};