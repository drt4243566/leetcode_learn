#include <iostream>
#include <vector>
using namespace std;
int s(vector<int> v, int index1, int index2);
int f(vector<int> v, int index1, int index2){
    if(index1==index2){
        return v[index1];
    }
    return max(v[index1]+s(v,index1+1,index2),v[index2]+s(v,index1,index2-1));
}
int s(vector<int> v, int index1, int index2){
    if(index1==index2){
        return 0;
    }
    return min(f(v,index1+1,index2),f(v,index1,index2-1));
}
void win(vector<int> v){
    if(v.empty()){
        return;
    }
    cout<<max(f(v,0,v.size()-1),s(v,0,v.size()-1))<<endl;
}
int win2(vector<int> arr) {
    if(arr.size() == 0) {
        return 0;
    }
    int L = arr.size();
    int f[L][L];
    int s[L][L];
    for(int i=0;i<arr.size();i++) {
        for(int j=0;j<arr.size();j++) {
            f[i][j] = 0;
            s[i][j] = 0;
        }
    }
    for(int j=0; j<arr.size();j++) {
        f[j][j] = arr[j];
        for(int i= j-1; i>=0; i--) {
            f[i][j] = max(arr[i] + s[i+1][j],arr[j] +s[i][j-1]);
            s[i][j] = min(f[i+1][j],f[i][j-1]);
        }
    }
    return max(f[0][L-1],s[0][L-1]);
}
int main(){
    vector<int> v{1,3,5,7,4,9};
    win(v);
    cout<<win2(v)<<endl;
    return 0;
}
