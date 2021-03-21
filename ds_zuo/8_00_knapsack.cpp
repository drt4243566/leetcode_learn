#include <iostream>
#include <vector>
using namespace std;
int process(vector<int> w, vector<int> v, int index, int already, int bag){
    if(already>=bag){
        return -1;
    }
    if(index == w.size()){
        return 0;
    }
    int L1 = process(w,v,index+1,already,bag);
    int L2 = -1;
    int L2next = process(w,v,index+1,already+w[index],bag);
    if(L2next !=-1){
        L2 = v[index] + L2next;
    }
    return max(L1,L2);

}
void knapsack(vector<int> w, vector<int> v, int bag){
    if(w.empty() or v.empty() or bag<=0){
        cerr<<"error"<<endl;
        return;
    }
    cout<<process(w,v,0,0,bag);
}
int main(){
    vector<int> w{3,2,6,7};
    vector<int> v{5,6,3,19};
    int bag = 15;
    knapsack(w,v,bag);
    return 0;
}
