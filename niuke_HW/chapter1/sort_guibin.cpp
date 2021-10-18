#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr,int L,int mid,int R){
    vector<int> helper(R-L+1,0);
    int i=0;
    int p1=L,p2=mid+1;
    while(p1<=mid && p2<=R){
        helper[i++] = arr[p1]<=arr[p2]?arr[p1++]:arr[p2++];
    }
    while (p1<=mid)
    {
        helper[i++] = arr[p1++];
    }
    while (p2<=R)
    {
        helper[i++] = arr[p2++];
    }
    for(int j=0;j<helper.size();j++){
        arr[L+j] = helper[j];
    }
}

void process(vector<int>& arr,int L,int R){
    if(L==R) return;
    int mid = L+(R-L)/2;
    process(arr,0,mid);
    process(arr,mid+1,R);
    merge(arr,L,mid,R);
}

int main(){
    vector<int> nums = {1,3,4,6,2,3,7};
    process(nums,0,nums.size()-1);
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}