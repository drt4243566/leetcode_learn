// 线段重合？
/* 坐标轴上有多个线段，互相之间可能重叠，(给定线段都有[1,3)这样的开始和结束位置)，求哪个位置重合的线段数目最多，返回这个重合数目*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class line{
public:
    int start=0;
    int end=0;
    line(int s,int e):start(s),end(e){}
};
bool compare(line& a,line& b){
    return a.start<b.start;
}
int main(){
    int N=0;
    cin >> N;
    vector<line> lines;
    for(int i=0;i<N;i++){
        line l1(0,0);
        cin >> l1.start >> l1.end;
        lines.push_back(l1);
    }
    sort(lines.begin(),lines.end(),compare);
    priority_queue<int,vector<int>,greater<int>> q;  // 小根堆
    int res=0;
    for(int i=0;i<N;i++){
        while(!q.empty()&&q.top()<lines[i].start){
            q.pop();
        }
        q.push(lines[i].end);
        int temp = q.size();
        res = max(res,temp);
    }
    cout << res;
    return 0;
}