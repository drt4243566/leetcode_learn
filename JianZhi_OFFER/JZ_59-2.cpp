#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

// 经典单调双端队列问题
class MaxQueue {
    // 双端单调队列
    deque<int> deque;
    // 除了双端队列，还需要一个队列记录所有元素
    queue<int> queue;
public:
    MaxQueue() {
    }
    
    int max_value() {
        if(deque.empty()) return -1;
        return deque.front();
    }
    
    void push_back(int value) {
        while(!deque.empty()&&deque.back()<value){
            deque.pop_back();
        }
        deque.push_back(value);
        queue.push(value);
    }
    
    int pop_front() {
        if(queue.empty()) return -1;
        int res = queue.front();
        if(res==deque.front()) deque.pop_front();
        queue.pop();
        return res;
    }
};
