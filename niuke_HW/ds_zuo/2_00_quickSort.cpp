#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class QuickSort{
public:
    void quickSort(int arr[], int n){
        if(arr == NULL || n < 2)
            return;
        quickSort_(arr, 0, n-1);
    }
    void quickSort_(int arr[], int L, int R){
        if(L < R){//不能使用if(L==R)return;R可能会小于L
            //swap(arr, L+(int)(rand()*(R-L+1)), R);
            vector<int> p = partition(arr, L, R);
            //p[0]相等区域的第一个位置，p[1]相等区域的最后一个位置
            quickSort_(arr, L, p[0]-1);
            quickSort_(arr, p[1]+1, R);
        }
    }
    vector<int> partition(int arr[], int L, int R){
        int less = L - 1;
        int more = R;
        while(L < more){
            if(arr[L] < arr[R]){
                swap(arr, ++less, L++);
            }else if(arr[L] > arr[R]){
                swap(arr, --more, L);
            }else{
                L++;
            }
        }
        swap(arr, more, R);
        return vector<int>{less+1,more};
    }
    void swap(int arr[],int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};

int main(){
    QuickSort N;
    int arr[12]={1,5,4,7,8,3,5,2,5,9,8,10};
    N.quickSort(arr, 12);
    for(int i=0;i<12;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}