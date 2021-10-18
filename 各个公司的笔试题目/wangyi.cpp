#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    vector<int> nums;
    int num = 0;
    int M=0;
    while(1){
        cin>>num;
        nums.push_back(num);
        if(cin.get()=='\n') break;
    }
    cin >> M;
    int n = nums.size();
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]<=M){
                res++;
            }
        }
    }
    cout << res <<endl;
    return 0;
}