#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    int N=0;
    int temp=0;
    unordered_set<int> flag;
    cin >> N;
    vector<int> nums(N,0);
    for(int i=0;i<N;i++){
        cin >> nums[i];
        if(flag.find(nums[i])!=flag.end()){
            cout << nums[i];
            break;
        }
        flag.insert(nums[i]);
    }
    return 0;
}