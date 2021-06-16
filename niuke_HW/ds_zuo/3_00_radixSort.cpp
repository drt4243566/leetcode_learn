#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;
int maxbits(int arr[],int N){
    int max = INT_MIN;
    for(int i=0; i<N; i++){
        if(max<arr[i]){
            max = arr[i];
        }
    }
    int res = 0;
    while(max){
        res++;
        max = max/10;
    }
    return res;
}
int getDigit(int x, int d){
    return (( x / ( (int)pow(10,d-1) )) % 10 );
}
void process(int arr[], int L, int R, int digit){
    const int radix  = 10;
    int i=0,j=0;
    int bucket[R-L+1]={0};
    for(int d = 1;d<= digit;d++){
        
        int count[radix]={0};
        for(i=L;i<=R;i++){
            j = getDigit(arr[i],d);
            count[j]++;
        }
        for(i=1;i<radix;i++){
            count[i] = count[i] + count[i-1];
        }
        /***********core*************/
        for(i = R;i>=L;i--){
            j= getDigit(arr[i],d);
            bucket[count[j]-1]=arr[i];
            count[j]--;
        }
        for(i=L,j=0;i<=R;i++,j++){
            arr[i] = bucket[j];
        }
    }
}
//only for no-negative value
void radixSort(int arr[], int N){
    if(N<=1)
        return;
    process(arr, 0, N-1, maxbits(arr,N));
}
int main(){
    
    int arr[]={12,587,685,1,245,548};
    radixSort(arr, 6);
    for(int i=0;i<6;i++){
    	cout<<arr[i]<<endl;
	} 
    return 1;
}