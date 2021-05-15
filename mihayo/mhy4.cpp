#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;
bool check(vector<int>&arr){
    for(int i=1;i<arr.size()-1;i++){
        int leftMax = arr[i];
        for(int j=i-1;j>=0;j--){
            leftMax = max(leftMax,arr[j]);
        }
        int rightMin = INT_MAX;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]>arr[i]){
                rightMin = min(rightMin,arr[j]);
            }
        }
        if(leftMax>arr[i]&&rightMin>arr[i]&&leftMax>rightMin) return true;
    }
    return false;
}

int main(){
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++){
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(check(arr))
            cout << "Yes" <<endl;
        else   
            cout << "No" <<endl;
    }
    return 0;
}