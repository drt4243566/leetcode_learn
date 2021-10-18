#include <iostream>
#include <vector>

using namespace std;
int main(){
    int t=0;
    while(t--){
        int n=0,m=0;
        cin>>n>>m;
        vector<int> rowSum(n,0);
        vector<int> colSum(m,0);
        rowSum[0] = (1+m)*m/2;
        colSum[0] = (1+m*(n-1))*n/2;
        int minV=INT_MAX,minH = INT_MAX;
        int sumV = colSum[0],sumH = rowSum[0];
        int preV=0,preH=0;
        for(int i=1;i<n;i++){
            rowSum[i] = rowSum[i-1]+m*n;
            sumH += rowSum[i];
        }
        for(int j=1;j<m;j++){
            colSum[j] = colSum[j-1]+n;
            sumV += colSum[j];
        }
        for(int v=2;v<=m;v++){
            preV += colSum[v-2];
            minV = min(minV,sumV-preV)
        }
    }
    return 0;
}