#include <iostream>
using namespace std;
#define ARR_NUM 1001
int visit[ARR_NUM];
int M, N;

int main(){
    cin>>M>>N;
    int i;
    for(i=1;i<=N;i++){
        visit[i]=0;
    }
    for(i=1;i<=N;i++){
        int temp1, temp2;
        cin>>temp1>>temp2;
        visit[temp1]=1;
        visit[temp2]=1;
    }
    int center;
    for(i=1;i<=M;i++){
        if(visit[i]==0){
            center = i;
            break;
        }
    }
    cout<<M-1<<endl;
    for(int i=1;i<=M;i++){
        if(i!=center){
            cout<<i<<" "<<center<<endl;
        }
    }


    return 0;
}