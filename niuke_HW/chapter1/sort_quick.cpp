#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& arr,int a,int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

vector<int> partition(vector<int>& arr,int L,int R){
    int less = L-1;
    int more = R;
    while(L<more){
        if(arr[L]<arr[R]){
            swap(arr,++less,L++);
        }else if(arr[L]>arr[R]){
            swap(arr,--more,L);
        }else{
            L++;
        }
    }
    swap(arr,more,R);
    return {less+1,more};
}

void RandomQuick(vector<int>& arr,int L,int R){
    if(L<R){
        swap(arr,R,L+rand()%(R-L+1));
        vector<int> p = partition(arr,L,R);
        RandomQuick(arr,L,p[0]-1);
        RandomQuick(arr,p[1]+1,R);
    }
}

int main(){
    vector<int> nums = {1,3,4,6,2,3,7};
    RandomQuick(nums,0,nums.size()-1);
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    int index = rand()%(5-3+1);
    cout << index << endl;
    return 0;
}