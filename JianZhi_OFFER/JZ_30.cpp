#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        A.push(x);
        // 出现比目前更小的元素时，才进入栈B当中;   而且避免了重复最小值被弹出的问题（弹出一次，少了多个最小值）；
        if(B.empty()||x<=B.top()) B.push(x);
    }
    
    void pop() {
        int num = A.top();
        A.pop();
        if(!B.empty() && (num==B.top())) B.pop();
    }
    
    int top() {
        return A.top();
    }
    
    int min() {
        return B.top();
    }

private:
    stack<int> A;       //存储全部数据
    stack<int> B;       //保存min值
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main(){

    return 0;
}