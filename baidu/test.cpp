#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct food
{
    int val;
    int index;
    food(int val1=0,int index1=0):val(val1),index(index1){}
};
bool compare(food a,food b){
    return a.val>b.val;
}

int main(){
    int T=0;
    cin >> T;
    while (T--)
    {
        int n,target;
        cin >> n >> target;
        vector<food> hungry;
        int index=1;
        for(int i=0;i<n;i++){
            food newf;
            cin>>newf.val;
            newf.index = index;
            index++;
            hungry.push_back(newf);
        }
        sort(hungry.begin(),hungry.end(),compare);
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum>=target){
                cout<<-1;
                break;
            }
            sum += hungry[i].val;
            cout << hungry[i].index+1 <<" ";
        }
        cout << endl;
    }
    return 0;
}