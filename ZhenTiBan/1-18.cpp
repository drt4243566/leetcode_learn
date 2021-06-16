#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
class Interval{
public:
    int start;
    int end;
};

bool cmp(Interval& a,Interval& b){
    return a.start<b.start;
}

vector<Interval> MergeInterval(vector<Interval>& intervals){
    if(intervals.size()<=1) return intervals;
    sort(intervals.begin(),intervals.end(),cmp);
    vector<Interval> res;
    // i的递增运算符这里依靠j来推进
    for(int i=0;i<intervals.size();){
        int start = intervals[i].start;
        int end = intervals[i].end;
        int j=i+1;
        for(;j<intervals.size()&&intervals[j].start<=end;j++){
            // 区间的开始位置已经按照升序的顺序进行排列
            // start = min(start,intervals[j].start);
            end = max(end,intervals[j].end);
        }
        res.push_back(Interval{start,end});
        i=j;
    }
    return res;
}

int main(){
    vector<Interval> intervals;
    int s,e;
    char ch;
    while(cin>>s>>ch>>e){
        intervals.push_back(Interval{s,e});
    }
    vector<Interval> res = MergeInterval(intervals);
    for(int i=0;i<res.size();i++){
        cout << res[i].start <<","<<res[i].end << " ";
    }
    return 0;
}