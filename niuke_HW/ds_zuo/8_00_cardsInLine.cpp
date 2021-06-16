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
int main(){
    vector<int> v{1,3,5};
    win(v);
    return 0;
}
