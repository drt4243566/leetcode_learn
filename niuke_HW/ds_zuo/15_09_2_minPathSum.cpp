#include <iostream>
#include <vector>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int process(vector<vector<int>> arr, int x, int y, int sum) {
    int n = arr.size();
    int m = arr[0].size();
    if(x == n-1 && y == m - 1) {
        return sum + arr[x][y];
    }
    if(x >= n or y >= m) {
        return -1;
    }
    sum = sum + arr[x][y];
    int m1 = process(arr, x+1, y, sum);
    int m2 = process(arr, x, y+1,sum);
    if(m1 == -1 and m2 == -1) return -1;
    else if(m1 == -1) return m2;
    else if(m2 == -1) return m1;
    else return min(m1,m2);
}
int minPath(vector<vector<int>> arr, int x, int y) {
    if(arr.size()==0 or arr[0].size() ==0) return 0;
    return process(arr, 0, 0, 0);
}
int main(){
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>> arr(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            arr[i].push_back(read());
        }
    }
    cout << minPath(arr, 0, 0) <<endl;
    
    return 0;
}
