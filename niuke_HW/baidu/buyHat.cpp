#include <iostream>
#include <set>
using namespace std;
int main(){
    int n,i,x;
    cin >> n;
    set<int> s;
    for(i=0;i<n;i++){
        cin>>x;
        s.insert(x);
    }
    if(s.size()<3) cout<<"-1";
    else{
        set<int>::iterator it = s.begin();
        it++;
        it++;
        printf("%d",*it);
    }
    return 0;
}
