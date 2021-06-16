#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 101
int M;
int x[N];
int y[N];
int visit[N];
int ans = 0;
queue<int> q;
void bfs(){
    while(!q.empty()){
        int t= q.front();
        q.pop();
        visit[t] = 1;
        for(int i=0;i<M;i++){
            if(!visit[i] &&(x[i]==x[t] || y[i] == y[t])){
                q.push(i);
            }
        }
    }
}
int main(){
    while(cin>>M){
        for(int i=0;i<M;i++){
                cin>>x[i]>>y[i];
                visit[i] = 0;
            }
            for(int i=0;i<M;i++){
                if(!visit[i]){
                    q.push(i);
                    bfs();
                    ans++;
            }
        }
        cout<<ans-1<<endl;
        ans = 0;
    }
    return 0;
}