#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        int i = 0;
        for(;i<intervals.size();i++){
            if(intervals[i].end <newInterval.start){
                result.push_back(intervals[i]);
            }else if(intervals[i].start > newInterval.end){
                break;
            }else{
                newInterval.start = min(newInterval.start,intervals[i].start);
                newInterval.end = max(newInterval.end,intervals[i].end);
            }
        }
        result.push_back(newInterval);
        for(;i<intervals.size();i++){
            result.push_back(intervals[i]);
        }

        return result;
    }

    bool comp(Interval &a, Interval &b){
        return a.start < b.start;
    }
};


int main(){


    return 0;
}