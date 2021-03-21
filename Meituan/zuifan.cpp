#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,t,c;
    vector<int> crime(n,0);
    cin>>n>>t>>c;
    for(int i=0;i<n;i++){
        int temp=0;
        cin >> temp;
        crime[i]=temp;
    }
    
    return 0;
}