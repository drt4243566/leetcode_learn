// 经典田忌赛马
// 田忌和齐王都有长度为N的数组，代表n匹马的能力值；

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printMa(vector<int>& horse,string des){
    cout << des+"的马：";
    for(auto element:horse){
        cout << element <<" ";
    }
    cout << endl;
}

int main(){
    cout << "田忌赛马"<<endl;
    int N=0;
    cin >> N;
    vector<int> qw(N,0),zj(N,0);
    cout << "邹忌："<<endl;
    for(int i=0;i<N;i++){
        cin >> zj[i];
    }
    cout << "齐王："<<endl;
    for(int j=0;j<N;j++){
        cin >> qw[j];
    }
    sort(zj.begin(),zj.end(),greater<int>());
    sort(qw.begin(),qw.end(),greater<int>());
    printMa(zj,"邹忌");
    printMa(qw,"齐王");
    int qhead=0,zhead=0;
    int qtail=N-1,ztail=N-1;
    int winCount=0,defeatCount=0;
    // 只要邹忌还有马就可以继续进行比较
    while(zhead<=ztail){
        // 邹忌下等马>齐王下等马
        if(zj[ztail]>qw[qtail]){
            ztail--;qtail--;
            winCount++;
        }
        // 邹忌下等马<齐王下等马
        else if(zj[ztail]<qw[qtail]){
            ztail--;qhead++;
            defeatCount++;
        }
        // 邹忌下等马=齐王下等马
        else{
            // 邹忌上等马>齐王上等马
            if(zj[zhead]>qw[qhead]){
                zhead++;qhead++;
                winCount++;
            }
            else{
                ztail--;qhead++;
                defeatCount++;
            }
        }
    }   
    cout << "邹忌胜场："<<winCount<<"  邹忌负场："<<defeatCount<<"  邹忌平局："<<N-winCount-defeatCount<<endl;
    return 0;
}