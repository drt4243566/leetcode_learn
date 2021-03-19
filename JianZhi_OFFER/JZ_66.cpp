#include <vector>
using namespace std;
// 分别维护两个dp数组
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        if(a.size()==0) return a;
        int len = a.size();
        vector<int> left(len,0);
        vector<int> right(len,0);
        left[0]=right[len-1]=1;

        for(int i=1;i<len;i++){
            left[i] = left[i-1]*a[i-1];
            right[len-i-1] = right[len-i]*a[len-i];
        }
        vector<int> res;
        for(int k=0;k<len;k++){
            res.push_back(left[k]*right[k]);
        }
        return res;
    }
};