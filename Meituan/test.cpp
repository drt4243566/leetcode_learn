#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

int main(){
    int n,m;
    unordered_map<int,int> mp;
    unordered_map<int,int> mp2;
    cin >> n;
    cin >> m;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        int value;
        cin >> value;
        a[i] = value;
    }  
    for(int i=0;i<n;i++){
        int value;
        cin >> value;
        b[i] = value;
        mp[b[i]] += 1;
    }  
    int x=0;
    for(;;){
        for(int i=0;i<n;i++){
            int value = (a[i]+x)%m;
            mp2[value]+=1;
        }
        if(mp2==mp){
            break;
        }
        else{
            x++;
            mp2.clear();
        }
    }
    cout << x <<endl; 
    return 0;
}