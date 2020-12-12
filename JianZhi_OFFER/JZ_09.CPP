#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//**考点：一个入栈，一个出栈，入栈有且仅有当出栈为空的时候。才能把元素送到出栈，否则会打乱顺序 **
//  时间复杂度： 入栈为O（1），出栈为O(N)

class CQueue
{
    stack<int> in;
    stack<int> out;
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        in.push(value);
    }
    int deleteHead()
    {
        if(in.empty()&&out.empty()){
            return -1;
        }
        else if(out.empty()&&!in.empty()){
            while(!in.empty()){
                int temp = in.top();
                in.pop();
                out.push(temp);
            }
        }
        int outValue = out.top();
        out.pop();
        return outValue;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */