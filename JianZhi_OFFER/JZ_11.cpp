#include <iostream>
#include <vector>

using namespace std;

// 二分法
class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        int left = 0;
        int right = numbers.size()-1;
        
        if(right==0){
            return numbers[0];
        }

        while(left<right){
            int mid = left + ((right - left) >> 1); // 移位运算符的优先级相当之低
            if(numbers[mid]>numbers[right]){   // 中间位置大于右边界，说明交界点位于右侧区域，且不包括mid自身
                left = mid +1;
            }
            else if(numbers[mid]<numbers[right]){  //  中间位置小于右边界，右侧区域有序，交界点位于左侧，包括mid自身
                right = mid;
            }
            else{ // 如果直接相等，暴力缩小右边界大小，由于右边界元素明显不唯一，所以可以去掉
                right--;
            }
        }
        return numbers[left];
    }
};

// 暴力法
class Solution1
{
public:
    int minArray(vector<int> &numbers)
    {
        int minNum = numbers[0];
        for (int i = 1; i < numbers.size(); i++)
        {
            if (numbers[i] < numbers[i - 1])
            {
                minNum = numbers[i] < minNum ? numbers[i] : minNum;
                break;
            }
        }
        return minNum;
    }
};