#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> v;
    int e1 = 0;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
        e1 = e1 ^ temp;
    }
    int rightOne = e1 & (~e1 + 1);
    int e2 = 0;
    for(int i=0; i<N; i++) {
        if((v[i] & rightOne) != 0) {
            e2 = e2 ^ v[i];
        }
    }
    e1 = e1 ^ e2;
    if(e1 > e2) {
        cout<<e2<<" "<<e1<<endl;
    } else {
        cout<<e1<<" "<<e2<<endl;
    }
    return 0;
}
