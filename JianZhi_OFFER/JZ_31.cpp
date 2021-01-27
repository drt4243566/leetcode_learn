#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        // 先设置一个辅助栈
        stack<int> stack;
        int j=0;
        for(int i=0;i<pushed.size();i++){
            stack.push(pushed[i]);
            // 有可能单次的POP将栈内现有的元素全部弹出，因此需要非空条件
            while(!stack.empty() && stack.top()==popped[j]){
                stack.pop();
                j++;
            }
        }
        return stack.empty();
    }
};