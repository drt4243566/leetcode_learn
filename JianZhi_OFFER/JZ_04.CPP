#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0, j = col-1;
        while (i<row&&j>=0) {
            if (matrix[i][j] > target)  j--;
            else if (matrix[i][j] < target)  i++;
            else return true;
        }
        return false;
    }
};

//      从右上角开始遍历，如果当前元素已经大于了target，则下方的所有元素必然也大于target，直接向左查找
//      右上角的元素代表了第一行的最大值；
//      问题相当于拆解为用每行最大的数字和target相比较，得到位于哪个子集的信息；
//      时间复杂度为：O（m+n）
//      更深层次的理解  ---  二叉搜索树


int main(){
    vector<vector<int>> dataArray = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
    Solution sol;
    bool res = sol.findNumberIn2DArray(dataArray, 21);
    string s = res ? "true" : "fasle";
    cout << s << endl;
    return 0;
}
