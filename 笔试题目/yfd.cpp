#include <iostream>
#include <vector>

using namespace std;
void FindSwapCard(vector<int>& cards);
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
    FindSwapCard(cards);
    return 0;
}

// 二分优化第二阶段
void FindSwapCard(vector<int>& cards){
    int flag1=0,flag2=0;
    int n = cards.size();
    // 第一阶段找到不是递增的元素
    for(int i=1;i<n;i++){
        if(cards[i]<cards[i-1]){
            flag1 = i-1;
            break;
        }
    }
    // 第二个元素只要找到比当前元素大的第一个元素即可
    int L = flag1 +1;
    int R = n-1;
    while(L<=R){
        int M = L+(R-L)/2;
        if(cards[M]>cards[flag1]){
            if(L==R) break;
            R = M;
        }
        else L = M+1;
    }
    if(L==n) flag2 = n-1;
    else flag2 = R-1;
    cout << flag1+1 <<" "<< flag2+1 << endl;
}