#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
using namespace std;
int searchcitys(vector<vector<int>>& res,int length,int city_nums,int city){
    if(city_nums==1&&city==0){
        return 1;
    }
    int curnum=0,curlength=0;
    stack<int> temp;
    int* isin = new int[city_nums];
    memset(isin,0,sizeof(int)*(city_nums));
    temp.push(city);
    isin[city] = 1;
    while (!temp.empty())
    {
        int curcity = temp.top();
        temp.pop();
        for(int i=0;i<city_nums;i++){
            if(curcity!=i && res[curcity][i]!=0&&(curlength+res[curcity][i])<=length&&isin[i]==0){
                temp.push(i);
                isin[i] = 1;
                curnum++;
            }
        }
    }
    return curnum;
}
int main(){
    int T=0;
    int j,k,d;
    int maxcity=0;
    int cityNode = 0;
    cin >> T;
    while(T){
        int city_nums=0,path_nums=0,length=0;
        vector<vector<int>> res(city_nums,vector<int>(city_nums,0));
        for(int i=0;i<path_nums;i++){
            cin >> j >> k >> d;
            res[j][k] = d;
            res[k][j] = d;
        }
        for(int i=0;i<city_nums;i++){
            int k = searchcitys(res,length,city_nums,i);
            if(k>=maxcity){
                if(k>maxcity)
                cityNode =1;
            }
        }
        
    }
    return 0;
}