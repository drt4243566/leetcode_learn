#include <iostream>
using namespace std;
#define MAXNUM 1000

int array[MAXNUM];
//大根堆
//使用数组的0位置
void swap(int arr[],int index1,int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void heapInsert(int arr[], int index){
    while(arr[index]>arr[(index-1)/2]){
        swap(arr,index,(index-1)/2);
        index = (index-1)/2;
    }
}
void heapify(int arr[], int index, int heapSize){
    int left = index*2 + 1;
    while(left<heapSize){
        int largest = left + 1 < heapSize && arr[left+1]>arr[left]?left+1:left;
        largest = arr[largest]>arr[index]?largest:index;
        if(largest == index) break;
        swap(arr,largest,index);
        index = largest;
        left = left*2 + 1;
    }
}
void heapSort(int arr[], int n){
    if(n<=1) return;
    for(int i =0;i<n;i++){
        heapInsert(arr,i);
    }
    int heapSize = n;
    swap(arr,0,--heapSize);
    while(heapSize>0){
        heapify(arr,0,heapSize);
        swap(arr,0,--heapSize);
    }
    
}
int main(){

    int array[10] = {1,4,6,6,8,9,2,10,5,7};
    heapSort(array,10);
    for(int i = 0;i<10;i++){
        cout<<array[i]<<" ";
    }

    return 0;
}