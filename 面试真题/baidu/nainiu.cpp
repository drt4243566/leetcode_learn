#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    vector<int> res = {2,123,215};
    vector<string> ans;
    for(int i=0;i<res.size();i++){
        ans.push_back(to_string(res[i]));
    }
    sort(ans.begin(),ans.end());
    for(string s:ans){
        cout<<s<<" ";
    }
    cout<<endl;
}