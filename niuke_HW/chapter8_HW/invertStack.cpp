#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int getStackLast(stack<int>& stk) //取出栈最底下的数字
{
    int result = stk.top();
    stk.pop();
    if (stk.size() == 0) {
        return result;
    } else {
        int last = getStackLast(stk);
        stk.push(result);
        return last;
    }
}

void reverse(stack<int>& stk)
{
    if (stk.size() > 0) {
        int num = getStackLast(stk);
        reverse(stk);
        stk.push(num);
    }
}

void printStack(stack<int> stk)
{
    while (stk.size() > 0) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    printStack(stk);
    cout << getStackLast(stk) << endl;
    printStack(stk);
    reverse(stk);
    printStack(stk);
    return 0;
}