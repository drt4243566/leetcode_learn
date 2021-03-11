#include <vector>
#include <math.h>
#include <iostream>
using namespace std; 
// 先是一手暴力法，这里的连续正数序列很关键; 时间复杂度比较特别O(target*sqrt(target))
class Solution1 {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> vec;
        vector<int> res;
        int sum=0,limit=(target-1)/2;
        // 要求正数序列，因此从1起步
        for(int i=1;i<=limit;i++){
            for(int j=i;;j++){
                sum+=j;
                // 一旦超出表明对应的i不可能
                if(sum>target){
                    sum=0;
                    break;
                }
                else if(sum==target){
                    // res存放成功的连续正数序列
                    res.clear();
                    for(int k=i;k<=j;k++){
                        res.emplace_back(k);
                    }
                    vec.emplace_back(res);
                    sum=0;
                    break;
                }
            }
        }
        return vec;
    }
};

// 枚举法+数学优化，利用一元二次方程进行逐个判断
class Solution2 {
public:
    vector<vector<int>> findContinuousSequence(int target){
        vector<vector<int>> vec;
        vector<int> res;
        int sum=0, limit=(target-1)/2;
        for(int x=1;x<=limit;x++){
            // 考虑到平方项有可能会超过int的范围
            long long delta = 1-4*(-x*1ll*x+x-2*target);
            // b^2-4ac<0可以直接认为没有实数根
            if(delta<0){
                continue;
            }
            int delta_sqrt = (int)sqrt(delta+0.5);
            // 满足b^2-4ac开根后为整数，且求根公式分子为偶数
            if(delta_sqrt*1ll*delta_sqrt==delta&&(delta_sqrt-1)%2==0){
                int y = (delta_sqrt-1)/2;
                if(x<y){
                    res.clear();
                    for(int i=x;i<=y;i++){
                        res.emplace_back(i);
                    }
                    vec.emplace_back(res);
                }
            }
        }
        return vec;
        
    }
};

// 双指针法 -- 相当于暴力法的优化，也就是滑动窗口法
class Solution3 {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>vec;
        vector<int> res;
        for(int left=1,right=2;left<right;){
            int sum = (left+right)*(right-left+1)/2;
            if(sum==target){
                res.clear();
                for(int i=left;i<=right;i++){
                    res.emplace_back(i);
                }
                vec.emplace_back(res);
                // 由于以left为起点的序列，最多只有一个可能等于target
                left++;
            }
            else if(sum<target){
                right++;
            }
            else{
                left++;
            }
        }
        return vec;
    }
};
// 滑动窗口法解题思路
vector<vector<int>> findContinuousSequence(int target) {
    int i=1;   //滑动窗口左边界
    int j=1;   //滑动窗口右边界
    int sum = 0;
    vector<vector<int>> vec;
    while(i<=target/2){
        // 右边界向右移动，向右移动才将j加入到滑动窗口当中，因此实际的区间为[i,j)；
        if(sum<target){
            sum+=j;
            j++;
        }
        // 左边界向右移动
        else if(sum>target){
            sum-=i;
            i++;
        }
        else{
            // 记录结果
            vector<int> res;
            for(int k=i;k<j;k++){
                res.push_back(k);
            }
            vec.push_back(res);
            sum -= i;
            i++;
        }
    }
    return vec;
}

int main(){
    long long delta=4;
    int delta_sqrt = (int)sqrt(delta+0.5);
    cout<<delta_sqrt;
    cout<<"\t"<<(int)(delta+0.5);
}
