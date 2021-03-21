#include <iostream>
#include <limits.h>
using namespace std;
//only for 0-200 value
void countSort(int arr[], int N){
    int max = INT_MIN;
    for(int i=0;i<N;i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    int bucket[max+1]={0};
    for(int i =0;i<N;i++){
        bucket[arr[i]]++;
    }
    for(int i=0,j=0;j<max+1;j++){
        while(bucket[j]-->0){
            arr[i++] = j;
        }
    }
}
int main(){

    int arr[]={5,5,5,3,2,1,4,6,5,4,3,2,1,6,7,8,9,4,3,2};
    countSort(arr,20);
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}