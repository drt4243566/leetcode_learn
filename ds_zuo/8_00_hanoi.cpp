#include <iostream>
#include <string>
using namespace std;
void hanoi_process(int N, string from, string to, string other){
    if(N==1){
        cout<<"Move 1 from "<<from<<" to "<<to<<endl;
    }
    else{
        hanoi_process(N-1,from,other,to);
        cout<<"Move "<<N<<" from "<<from<<" to "<<to<<endl;
        hanoi_process(N-1, other, to, from);
    }
}
void hanoi(int n){
    if(n>0){
        hanoi_process(n,"lef","rig","mid");
    }
}
int main(){

    hanoi(5);

    return 0;
}