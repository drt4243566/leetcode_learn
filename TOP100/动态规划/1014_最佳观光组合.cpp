class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // values[i] + values[j] + i - j 拆分成 values[i]+i 和 values[j]-j，当固定j，相当于在找[0,j)上最大的values[i]+i;
        // 这里把 values[i]+i 的最大值用 maxVal 进行表示；
        int n = values.size();
        int maxVal = values[0];
        int res = 0;
        for(int i=1;i<n;i++){
            res = max(res, maxVal+values[i]-i);
            maxVal = max(maxVal,values[i]+i);
        }
        return res;
    }
};