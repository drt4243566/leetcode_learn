#include <iostream>
#include <vector>
using namespace std;
/*
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
class Solution {
public:
    /*      O(nlogn)     */
    bool Find(int target, vector<vector<int> > array) {
        for(int row=0;row<array.size();row++)
        {
            int L = 0;
            int R = array[row].size()-1;
            int Mid;
            while(L<=R)
            {

                Mid = L + ((R-L)>>1);
                //cout<<L<<" "<<R<<" "<<Mid<<endl;
                if(target == array[row][Mid])
                {
                    return true;
                }
                else if(target < array[row][Mid])
                {
                    R = Mid - 1;
                }
                else
                {
                    L = Mid + 1;
                }
                
            }
        }
        return false;
    }
    /*   o(m+n)    */
    bool Find2(int target, vector<vector<int> > array) {
        int row = 0;
        int col = array[0].size() - 1;

        while((row < array.size()) && (col >= 0)){
            if(target == array[row][col])
            {
                return true;
            }
            else if(target < array[row][col])
            {
                col--;
            }
            else
            {
                row++;
            }
            
        }
        return false;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> array{{1,2,8,9},{4,7,10,13}};
    cout<<S.Find2(15,array)<<endl;

    return 0;
}