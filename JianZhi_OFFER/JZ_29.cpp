#include <iostream>
#include <vector>

using namespace std;

// 设定好四个边界，左右上下，依次循环；
// 细节1 -> r和b的初值为size()-1；
// 细节2 -> 结束条件为 ( ++l>r )
class Solution{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return {};
        vector<int> res;
        int l = 0;                    // 左边界
        int r = matrix[0].size() - 1; // 右边界
        int t = 0;                    // 上边界
        int b = matrix.size() - 1;    // 下边界
        while (true)
        {
            //从左到右
            for (int j = l; j <= r; j++)
                res.push_back(matrix[t][j]);
            //t++;
            if (++t > b)
                break;
            //从上到下
            for (int i = t; i <= b; i++)
                res.push_back(matrix[i][r]);
            if (--r < l)
                break;
            //从右向左
            for (int j = r; j >= l; j--)
                res.push_back(matrix[b][j]);
            if (--b < t)
                break;
            //从下到上
            for (int i = b; i >= t; i--)
                res.push_back(matrix[i][l]);
            if (++l > r)
                break;
        }
        return res;
    }
};