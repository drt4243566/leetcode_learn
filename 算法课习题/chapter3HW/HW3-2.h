#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Definition for an interval.
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution1 {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> Res;
        int index=0;
        //�����ƽ��Ĺ��̣�����������new���ұ߽絽ͷ��������merge�����ǣ���new����߽�����
        //interval[i]��ʱ������new,����ֱ��push_back��ǰԪ��
        for (int i = 0; i < intervals.size(); i++) {
            if (newInterval.end < intervals[i].start) {
                index = i;
                break;
            }
            else if (newInterval.start <= intervals[i].end) {
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
            }
            else
                Res.push_back(intervals[i]);
        }
        Res.push_back(newInterval);
        for (; index < intervals.size(); index++) {
            Res.push_back(intervals[index]);
        }
        return Res;
    }
};