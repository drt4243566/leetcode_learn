#include <iostream>
#include <vector>
using namespace std;
void infect(vector<vector<int>> &m, int i, int j, int N, int M){
    if(i<0 or i>=N or j<0 or j>=M or m[i][j]!=1){
        return;
    }
    m[i][j] = 2;
    infect(m,i,j-1,N,M);
    infect(m,i,j+1,N,M);
    infect(m,i-1,j,N,M);
    infect(m,i+1,j,N,M);
}
int countIsLands(vector<vector<int>> m){
    int res = 0;
    if(m.empty() or m[0].empty()){
            return 0;
    }
    int N = m.size();
    int M = m[0].size();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(m[i][j]==1){
                res++;
                infect(m,i,j,N,M);
            }
        }
    }
    return res;
}
int main(){
    vector<vector<int>> m{
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
        { 0, 1, 1, 1, 1, 0, 1, 1, 0 }, 
        { 0, 1, 1, 1, 0, 0, 0, 1, 0 },
        { 0, 1, 1, 0, 0, 0, 1, 1, 0 }, 
        { 0, 0, 0, 0, 0, 1, 1, 0, 0 }, 
        { 0, 0, 0, 0, 1, 1, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
    };
    cout<<countIsLands(m)<<endl;

    return 0;
}
