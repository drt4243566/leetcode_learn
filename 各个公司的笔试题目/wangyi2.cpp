#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    vector<int> kids;
    int kid=0;
    int maxAge = 0;
    while (1)
    {
        cin>>kid;
        kids.push_back(kid);
        maxAge = max(maxAge,kid);
        if(cin.get()=='\n') break;
    }
    int n = kids.size();
    sort(kids.begin(),kids.end());
    int sum = 1;
    int card = 1;
    for(int i=1;i<n;i++){
        if(kids[i]==kids[i-1]){
            card = 1;
        }else{
            card++;
        }
        if(i==n-1&&kids[i]!=kids[0]){
            card=2;
        }
        sum += card;
    }
    cout << sum <<endl;
}

// 1 1 2 2