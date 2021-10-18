#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct Node{
    int val;
    int i;
    int j;
    Node(int v,int v1,int v2):val(v),i(v1),j(v2){};
};

int main(){
    int N=0,M=0;
    cin >> N >> M;
    unordered_map<int,vector<int>> dic;
    vector<vector<int>> res(N,vector<int>(M,-1));
    int node = 0;
    for(int i=1;i<=N*M;i++){
        int key=0;
        vector<int> nums;
        cin >> key;
        int flag_zero = 0;
        for(int i=0;i<4;i++){
            int num = 0;
            cin >> num;
            if(num==0&&i==0) flag_zero++;
            if(num==0&&i==1) flag_zero++;
            nums.push_back(num);
        }
        if(flag_zero==2){
            node = key;
            res[0][0] = node;
        }
        dic[key] = nums;
    }
    queue<Node> q;
    q.push(Node(node,0,0));
    while(!q.empty()){
        Node t = q.front();
        q.pop();
        if(dic[t.val][2]!=0 && t.i>=0 && t.i<N && t.j+1>=0 && t.j+1<M && res[t.i][t.j+1]<0){
            q.push(Node(dic[t.val][2],t.i,t.j+1));
            res[t.i][t.j+1] = dic[t.val][2];
        }
        if(dic[t.val][3]!=0 && t.i+1>=0 && t.i+1<N && t.j>=0 && t.j<M && res[t.i+1][t.j]<0){
            q.push(Node(dic[t.val][3],t.i+1,t.j));
            res[t.i+1][t.j] = dic[t.val][3];
        }
    }
    // 输出
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}