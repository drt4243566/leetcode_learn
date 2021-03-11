#include <iostream>
#include <vector>
using namespace std;

// 堆排序 -- 大根堆
/* 先从堆结构起步，有两个核心功能：add(把一个数字加入到堆中)和popMax（将堆结构中最大的元素弹出）
   引申一下，可以得到heapInsert函数和heapify函数*/
void swap(vector<int>& nums,int a,int b){
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
}
// heapInsert函数默认在[0,index-1]的区间上已经存在排序好的堆结构，即将添加新的Index位置的元素
// 整体上来看是从下往上进行比较的思想
void heapInsert(vector<int>& nums,int index){
    // 当子节点大于父节点元素时，就交换
    while(nums[index]>nums[(index-1)/2]){
        swap(nums,index,(index-1)/2);
        index = (index-1)/2;
    }
}

// heapify函数弹出最大值，先将根节点和最右侧节点交换，然后删除最后一个元素（有效区的长度-1），再从上向下进行比较
// index表示开始比较的位置，heapSize表示有效区为：[0,heapSize)
void heapify(vector<int>& nums,int index,int heapSize){
    // 左孩子的下标
    int left = index*2+1;
    // 当下方还有左孩子的时候进行判断
    while (left<heapSize)
    {
        int largest = (left+1)<heapSize&&(nums[left+1]>nums[left])?left+1:left;
        largest = nums[largest]>nums[index]?largest:index;
        // 只要比不过父节点，直接就不需要继续比较
        if(largest==index) break;
        swap(nums,largest,index);
        index = largest;
        left = index*2+1;
    }
}

// 堆排序函数，有两种实现形式：
// 1.当数据是逐条输入的情况，先采用heapInsert将元素输入，再从上到下整一波heapify
void heapSort1(vector<int>& nums){
    if(nums.size()<2) return;
    // 先把大根堆构造出来
    for(int i=0;i<nums.size();i++){
        heapInsert(nums,i);
    }
    // 在大根堆的基础上对，每个节点进行heapify()
    int heapSize = nums.size();
    // 交换根节点和最后一个节点
    swap(nums,0,--heapSize);
    while(heapSize>0){
        heapify(nums,0,heapSize);
        swap(nums,0,--heapSize);
    }
}
// 2.当数据直接以数组形式给出，直接从后往前循环heapify解决
void heapSort2(vector<int>& nums){
    if(nums.size()<2) return;
    // 得到大根堆
    for(int i=nums.size()-1;i>=0;i--){
        heapify(nums,i,nums.size());
    }
    // 不断缩小heapSize有效区的范围，弹出最大值
    int heapSize = nums.size();
    swap(nums,0,--heapSize);    // 弹出最大值
    while(heapSize>0){
        heapify(nums,0,heapSize);
        swap(nums,0,--heapSize);
    }
}

void printfNums(vector<int>& nums){
    for(int i:nums){
        cout<<i<<" ";
    }
    cout << endl;
}

int main(){
    vector<int> nums = {4,3,5,7,6,9,2,10,8,13};
    heapSort1(nums);
    printfNums(nums);
    heapSort2(nums);
    printfNums(nums);
    return 0;
}