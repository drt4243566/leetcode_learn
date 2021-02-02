#include <iostream>
#include <vector>
#include <queue>
#include <time.h>
using namespace std;

// 构建长度为K的大根堆
class Solution1{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k){
        vector<int> vec(k,0);
        if(k==0){
            return {};
        }
        // c++的优先队列就是大根堆的现成形式，默认参数less<int>
        priority_queue<int> Q;
        for(int i=0;i<k;i++){
            Q.push(arr[i]);
        }
        // 在预先填满k个元素之后，弹出堆顶元素/更大的元素
        for(int i=k;i<arr.size();i++){
            if(Q.top()>arr[i]){
                Q.pop();
                Q.push(arr[i]);
            }
        }
        // 最后所剩的k个元素即为最小值
        for(int i=0;i<k;i++){
            vec[i]=Q.top();
            Q.pop();
        }
        return vec;
    }
};

// 基于快排思想的快速选择法、
class Solution2{
private:
    // 普通版本下的分区算法，默认使用最后一个元素作为划分值
    // 快排partition大于小于区都要划分，这里只管小于区
    int partition(vector<int>& nums,int L,int R){
        int pivot = nums[R];
        int i = L-1;     //小于区边界 
        for(int j=L;j<=R-1;++j){
            if(nums[j]<=pivot){
                swap(nums[++i],nums[j]);
            }
        }
        swap(nums[i+1],nums[R]);    //将划分值置于小于区右侧第一个元素
        return i+1;
    }
    // 基于随机划分的版本
    int randomized_partition(vector<int> &nums, int L, int R){
        int i = rand()%(R-L+1)+L;
        swap(nums[i],nums[R]);
        return partition(nums,L,R);
    }
    // 快速选择
    void randomized_selected(vector<int>& arr,int L,int R,int k){
        if(L>=R) return;
        int pos = randomized_partition(arr,L,R);
        // pos是划分值在数组中的位置，表示第Num小的数字
        int num = pos-L+1;
        if(num==k) return;
        //num<k，说明第k小的数字在划分值的右侧
        else if(num<k){
            randomized_selected(arr,pos+1,R,k-num);
        }
        else{
            randomized_selected(arr,L,pos-1,k);
        }
    }
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k){
        srand((unsigned)time(NULL));
        randomized_selected(arr,0,arr.size()-1,k);
        vector<int> vec;
        for(int i=0;i<k;i++){
            vec.push_back(arr[i]);
        }
        return vec;
    }
};

int main(){
    vector<int> testArr{1,2,4,6,7,8,9,0,23,3,213,45,67,87};
    Solution2 sol2;
    vector<int> res = sol2.getLeastNumbers(testArr,3);
    // 输出时间，可以用做srand()函数的参数
    cout << time(NULL);
    return 0;
}