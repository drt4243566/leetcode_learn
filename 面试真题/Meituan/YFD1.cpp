#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n=0,target=0;
    cin >> n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> target;
    int start=0;
    vector<int> count;
    int sum=0;
    for(int i=0;i<n;i++){
        sum |= arr[i];
        if(sum>target){
            count.push_back(i-start);
            start = i+1;
            sum = 0;
        }
        if(i==n-1){
            count.push_back(i-start);
        }
    }
    long res=0;
    for(int j=0;j<count.size();j++){
        long temp = (count[j]*(count[j]+1)/2)%1000000007;
        res = (res+temp)%1000000007;
    }
    cout << res <<endl;
    return 0;
}