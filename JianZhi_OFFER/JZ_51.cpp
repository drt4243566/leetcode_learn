#include <vector>
using namespace std;
class Solution {
public:
    int reverseRecur(vector<int>& nums,vector<int>& tmp,int left,int right){
        if(left==right) return 0;
        // mid变量向下取整，当剩余元素个数为2时，mid必然取到左边界，符合边界设定
        int mid = left+(right-left)/2;
        int leftPair = reverseRecur(nums,tmp,left,mid);
        int rightPair = reverseRecur(nums,tmp,mid+1,right);
        int crossPair = mergeSort(nums,tmp,left,mid,right);
        return leftPair+rightPair+crossPair;
    } 

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;
        // 提前开辟辅助数组（只开辟一个足够大的数组，避免反复申请删除）
        vector<int> tmp(n);
        // 此处的区间表示[left,right]（左闭右闭）
        return reverseRecur(nums,tmp,0,n-1);
    }
    // 真正的合并函数
    int mergeSort(vector<int>& nums,vector<int>& tmp,int left,int mid,int right){
        // 只拷贝需要的长度
        for(int i = left;i<=right;i++){
            tmp[i] = nums[i];
        }
        // i,j分别遍历左右子区间
        int i = left;
        int j = mid+1;
        int count = 0;
        // 变量k遍历整个nums的 [left,right]
        for(int k=left; k<=right; k++){
            if(i>mid){
                nums[k] = tmp[j++];
            }else if(j>right){
                nums[k] = tmp[i++];
            }else if(tmp[i]<=tmp[j]){ //此处的小于等于号
                nums[k] = tmp[i++];
            }else{                 // 右侧子区间归并时需要计算逆序对
                nums[k] = tmp[j++];
                count += mid-i+1;
            }
        }
        return count;
    }
};

// 经典归并排序
void merge(vector<int>& arr,int L,int mid,int R){
    vector<int> helper(R-L+1,0);
    int i=0;
    int p1 = L;
    int p2 = mid+1;
    while(p1<=mid && p2<=R){
        helper[i++] = arr[p1]<=arr[p2]?arr[p1++]:arr[p2++];
    }
    while(p1<=mid){
        helper[i++] = arr[p1++];
    }
    while(p2<=mid){
        helper[i++] = arr[p2++];
    }
    for(int i=0;i<helper.size();i++){
        arr[L+i] = helper[i];
    }
}

void process(vector<int>& arr,int L,int R){
    if(L==R){
        return;
    }
    int mid = L+(R-L)/2;
    process(arr,L,mid);
    process(arr,mid+1,R);
    merge(arr,L,mid,R);
}