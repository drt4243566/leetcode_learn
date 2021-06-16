#include <iostream>
using namespace std;
#define MAXNUM 100000

int array[MAXNUM];
int M;
int flag;

class MergeSort{
    public:
        void mergeSort(int arr[],int M){
            if(M<=1)return;
            partition(arr, 0, M-1);
        }
        void partition(int arr[],int L,int R){
            if(L == R)return;
            int Mid = L +((R - L)>>1);
            partition(arr, L, Mid);
            partition(arr, Mid+1, R);
            merge(arr, L, Mid, R);
        }
        void merge(int arr[],int L,int Mid,int R){
            int indexL = L;
            int indexR = Mid + 1;
            int *temp = new int[R-L+1];
            int p = 0;
            while(indexL<=Mid && indexR<=R){
                if(flag == 0){
                    if(arr[indexL]<=arr[indexR]){
                        temp[p++] = arr[indexL++];
                    }
                    else{
                        temp[p++] = arr[indexR++];
                    }
                }else
                {
                    if(arr[indexL]>=arr[indexR]){
                        temp[p++] = arr[indexL++];
                    }
                    else{
                        temp[p++] = arr[indexR++];
                    }
                }
            }
            while(indexL<=Mid){
                temp[p++] = arr[indexL++];
            }
            while(indexR<=R){
                temp[p++] = arr[indexR++];
            }
            p = 0;
            while(L<=R){
                arr[L++] = temp[p++];
            }
            delete [] temp;

        }
};



int main(){
    MergeSort S;
    while(cin>>M){
        for(int i=0;i<M;i++){
            cin>>array[i];
        }
        cin>>flag;
        S.mergeSort(array,M);
        //output
        cout<<array[0];
        for(int i=1;i<M;i++){
            cout<<" "<<array[i];
        }
        cout<<endl;
    }

    return 0;
}