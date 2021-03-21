#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m;
    cin >> n;
    cin >> m;
    vector<vector<int>> a(m,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int value;
            cin >> value;
            a[i][j] = value;
        }
    }
    vector<int> zr(m,0);
    zr[0] = 0;
    zr[1] = 1;
    for(int i=2;i<m;i++){
        zr[i] = a[zr[i-1]][zr[i-2]]-1;
        if(zr[i]==zr[i-1]){
            zr[i]=a[zr[i-1]][zr[i-1]]-1;
        }
    }
    cout << zr[m-1];
}