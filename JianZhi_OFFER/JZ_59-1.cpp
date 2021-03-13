#include <vector>
#include <deque>
using namespace std;
// 单调队列
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size()==0||k==0) return res;
        // 单调队列，保持递减序列
        deque<int> deque;
        // i的实际范围是从[1-k,n-k],j的范围是[0,n-1]
        for(int j=0,i=1-k;j<nums.size();i++,j++){
            // 删除deque中的nums[i-1]元素，这里注意i>0 -- 而且要注意这里是当前窗口和上一个窗口的比较
            if(i>0&&deque.front()==nums[i-1]) deque.pop_front();
            // 保持deque递减,较小的元素都去掉 -- [最大值 次大值 ... 刚进来的元素] 前面比刚进来元素小的全部删除
            while(!deque.empty()&&nums[j]>deque.back()){
                deque.pop_back();
            }
            deque.push_back(nums[j]);
            // 记录窗口最大值
            if(i>=0) res.push_back(deque.front());
        }
        return res;
    }
};

// 将未形成窗口的部分单独循环
class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size()==0||k==0) return res;
        // 单调队列，保持递减序列
        deque<int> deque;
        // 未形成窗口时
        for(int i=0;i<k;i++){
            while(!deque.empty()&&deque.back()<nums[i]){
                deque.pop_back();
            }
            deque.push_back(nums[i]);
        }
        res.push_back(deque.front());
        // 形成窗口后
        for(int j=k;j<nums.size();j++){
            if(deque.front()==nums[j-k]) deque.pop_front();
            while(!deque.empty()&&deque.back()<nums[j]) deque.pop_back();
            deque.push_back(nums[j]);
            res.push_back(deque.front());
        }
        return res;
    }
};