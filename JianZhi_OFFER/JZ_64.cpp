using namespace std;

// 利用逻辑运算符的短路效应
class Solution {
public:
    int sumNums(int n) {
        int sum = n;
        // 当n==1时，&&逻辑符直接短路，结束递归，返回sum
        bool flag = sum>1&&(sum+=sumNums(n-1))>0;
        return sum;
    }
};