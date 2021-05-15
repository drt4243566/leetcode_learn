#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(){
    vector<int> chops = {1,1,2,2,2};
    //unordered_map<int,int> mp;
    int n = chops.size();
    sort(chops.begin(),chops.end());
    int sum=0;
    for(int i=0;i<n;i++){
        sum += chops[i];
    }
    double temp = sum/4.0;
    int edge = sum/4;
    if(edge!=temp) cout<<"false";
    int equal_count=0;
    int i=0;
    int preSum=0;
    for(;i<n;i++){
        if(chops[i]>edge) cout << "false";
        else if(chops[i]==edge) break;
        else preSum+=chops[i];
    }
    int rest = 4-n+i;
    if(rest==1){
        if(preSum==edge) cout<<"true";
        else cout<<"false";
    }
    else if(rest==2)
    return 0;
}