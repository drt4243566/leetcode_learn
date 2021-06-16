#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define MAXNUM 550
using namespace std;
int arr[MAXNUM][MAXNUM]={0};

int main(){
    int swordNum;
    cin>>swordNum;
    int temp;
    for(int i=1;i<swordNum;i++){
        for(int j=i+1;j<=swordNum;j++){
            cin>>temp;
            arr[i][j] = temp;
            arr[j][i] = temp;
        }
    }
    int result,firstMax,secondMax;
    result = 0;
    for(int i=1;i<=swordNum;i++){
        firstMax = 0;
        secondMax = 0;
        for(int j=1;j<=swordNum;j++){
            if(firstMax < arr[i][j]){
                secondMax = firstMax;
                firstMax = arr[i][j];
            }
            else if(secondMax < arr[i][j]){
                secondMax = arr[i][j];
            }
        }
        if(result < secondMax){
            result = secondMax;
        }
    }
    cout<<1<<endl;
    cout<<result<<endl;

    return 0;

}