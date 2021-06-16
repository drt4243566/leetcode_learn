#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int>& arr);
// 保持大根堆的插入过程，这个过程的[0,index-1]范围上已经是
void heapInsert(vector<int>& arr,int index){
    while(arr[index]>arr[(index-1)/2]){
        swap(arr[index],arr[(index-1)/2]);
        index = (index-1)/2;
    }
}

// 将index位置(根节点)的元素逐次向下作比较；指定有效区的范围；
void heapify(vector<int>& arr,int index,int heapSize){
    int left = 2*index+1;
    while(left<heapSize){
        // 首先要获得左右孩子的最大值,此处left+1必须< heapSize，所以这里实际上是个开区间
        int largest = (left+1<heapSize)&&(arr[left+1]>arr[left])?left+1:left;
        // 再判断孩子节点值和父节点值的大小
        largest = arr[largest]>arr[index]?largest:index;
        // 如果父节点出终止下沉，直接跳出
        if(largest==index) break;
        // 父节点下沉
        swap(arr[largest],arr[index]);
        // 当前节点下移
        index = largest;
        // 获取最新的左孩子节点
        left = 2*index+1;
    }
}

void heapsort(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        heapInsert(arr,i);
    }
    int heapSize = n;
    // 注意 --heapSize
    swap(arr[0],arr[--heapSize]);
    while(heapSize>0){
        heapify(arr,0,heapSize);
        swap(arr[0],arr[--heapSize]);
    }
}

void printArr(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {2,4,5,6,7,8,1};
    heapsort(arr);
    printArr(arr);
    return 0;
}