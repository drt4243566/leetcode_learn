#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> cards;
    int flag1=0,flag2=0;
    int SingleCard = 0;
    while(cin >> SingleCard){
        cards.push_back(SingleCard);
    }
    int n=cards.size();
    for(int i=1;i<n;i++){
        if(cards[i]<cards[i-1]){
            flag1 = i-1;
            break;
        }
    }
    int j=flag1+1;
    for(;j<n;j++){
        if(cards[j]>cards[flag1]){
            flag2 = j-1;
            break;
        }
    }
    if(j==n) flag2 = n-1;
    cout << flag1+1 <<" "<< flag2+1 << endl;
    return 0;
}