#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

//  unordered_map<int,unordered_map<int,bool>> mmp;  // 学到了这个多重嵌套的hashmap

class Node{
public:
    int arr1;
    int arr2;
    int sum;
    Node(int a1,int a2,int s):arr1(a1),arr2(a2),sum(s){}
    bool operator<(const Node& n) const{
        return sum<n.sum;
    }
};

unordered_map<int,unordered_map<int,bool>> set;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N=0,k=0;
    cin >> N >>k;
    vector<int> arr1(N,0);
    vector<int> arr2(N,0);
    vector<int> res(k,0);
    for(int i=0;i<N;i++){
        cin >> arr1[i];
    }
    for(int j=0;j<N;j++){
        cin >> arr2[j];
    }
    priority_queue<Node> q;
    /*  二维数组占用内存过多
    bool set[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            set[i][j] = false;
        }
    }*/
    q.push((Node){N-1,N-1,arr1[N-1]+arr2[N-1]});
    set[N-1][N-1] = true;
    int cnt=0;
    while(cnt<k){
        Node cur = q.top();
        q.pop();
        res[cnt++] = cur.sum;
        int arrone = cur.arr1;
        int arrtwo = cur.arr2;
        // 向上
        if(arrone-1>=0&&!set[arrone-1][arrtwo]){
            q.push((Node){arrone-1,arrtwo,arr1[arrone-1]+arr2[arrtwo]});
            set[arrone-1][arrtwo]=true;
        }
        // 向左
        if(arrtwo-1>=0&&!set[arrone][arrtwo-1]){
            q.push((Node){arrone,arrtwo-1,arr1[arrone]+arr2[arrtwo-1]});
            set[arrone][arrtwo-1]=true;
        }
    }
    for(int i:res) cout << i << " ";
    return 0;
}