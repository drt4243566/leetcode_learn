#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct food
{
    int val;
    int idx;
};
bool compare(food a,food b){
    return a.val>b.val;
}
int main(){
    int T;
    int N,M;
    cin >> T;
    while(T--){
        cin>>N>>M;
        vector<food> hungry;
        for(int i=0;i<N;i++){
            food temp;
            cin >> temp.val;
            temp.idx=i;
            hungry.push_back(temp);
        }
        sort(hungry.begin(),hungry.end(),compare);
        int sum=0;
        vector<int> a;
        for(int i=0;i<hungry.size();i++){
            sum += hungry[i].val;
            a.push_back(hungry[i].idx);
            if(sum>=M){
                break;
            }
        }
        if(sum<M){
            cout<<-1<<endl;
            continue;
        }
        cout<<a.size()<<endl;
        for(int i=0;i<a.size();i++){
            cout<<a[i]+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
