#include <iostream>
#include <vector>

using namespace std;

void heapInsert(vector<int>& arr,int index){
    while(arr[index]>arr[(index-1)/2]){
        swap(arr[index],arr[(index-1)/2]);
        index = (index-1)/2;
    }
}

void heapify(vector<int>& arr,int index,int heapSize){
    int left = 2*index+1;
    // 关键是这里是小于号
    while(left<heapSize){
        int largest = (left+1<heapSize)&&(arr[left+1]>arr[left])?left+1:left;
        largest = arr[largest]>arr[index]?largest:index;
        if(largest==index) break;
        swap(arr[index],arr[largest]);
        index = largest;
        left = 2*index+1;
    }
}

// 这里需要先将根节点放到最后，然后交换
void heapSort(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        heapInsert(arr,i);
    }
    int heapSize = arr.size()-1;
    swap(arr[0],arr[heapSize]);
    // 只剩下一个元素就不需要heapify
    while(heapSize>0){
        heapify(arr,0,heapSize);
        swap(arr[0],arr[--heapSize]);
    }
}

int main(){
    vector<int> nums = {1,3,4,6,2,3,7};
    heapSort(nums);
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}