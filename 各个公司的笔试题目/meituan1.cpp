#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    int res=0;
    cin >> n;
    vector<vector<int>> mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mp[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mp[i][j]>0){
                
            }
        }
    }
    cout << res <<endl;
    return 0;
}