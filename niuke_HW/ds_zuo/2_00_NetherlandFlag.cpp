#include <iostream>
using namespace std;

class NetherlandFlag{
public:
    void partition(int arr[],int L, int R, int p){
        int less = L - 1;
        int more = R + 1;
        while(L < more){
            if(arr[L] < p){
                swap(arr, ++less, L++);
            }else if(arr[L] > p){
                swap(arr, --more, L);
            }else{
                L++;
            }
        }
    }
    void swap(int arr[],int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};

int main(){
    NetherlandFlag N;
    int arr[12]={1,5,4,7,8,3,5,2,5,9,8,10};
    N.partition(arr, 0, 11, 5);
    for(int &x:arr){
        cout<<x<<" ";
    }

    return 0;
}