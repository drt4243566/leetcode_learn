#include <iostream>
using namespace std;
int com(int x, int y){
    if(x == y){
        return x;
    }
    if(x > y){
        return com(x/2, y);
    }
    if(x < y){
        return com(x, y/2);
    }
}
int main(){
    int m, n;
    while(cin>>m>>n){
        cout<<com(m,n)<<endl;
    }

    return 0;
}