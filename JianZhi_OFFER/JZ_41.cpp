#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class MedianFinder
{
    // 大根堆存储右侧较小的一半
    priority_queue<int, vector<int>, less<int>> maxHeap;
    // 小根堆储存左侧较大的一半
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    /** initialize your data structure here. */
    MedianFinder(){}

    void addNum(int num)
    {
        /* 大小根堆间要保持数量的稳定，总数为奇数时，左侧小根堆多一个元素，总数偶数时，二者元素个数相等
           因此，当目前数字个数为奇数时，向右侧大根堆添加数字，反之当前为偶数时，向左侧小根堆添加；
           添加元素时，不能直接加入，因为有可能数字是另一半边的元素，这波要以退为进，如果当前为偶数个，先
           进入右侧大根堆，再将弹出的数字加入左侧
        */
       if(maxHeap.size()==minHeap.size()){      //当前偶数个数，先进大根堆
            maxHeap.push(num);
            int tmp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(tmp);
       }
       else{                                    //不相等则说明目前个数为奇数
            minHeap.push(num);
            int tmp = minHeap.top();
            minHeap.pop();
            maxHeap.push(tmp);
       }
    }

    double findMedian()
    {
        if(maxHeap.size()==minHeap.size()){
            return (maxHeap.top()+minHeap.top())/2.0;
        }
        else return minHeap.top()*1.0;
    }
};

int main(){
    MedianFinder M1;
    M1.addNum(1);
    M1.addNum(2);
    double res = M1.findMedian();
    cout << res <<endl;
    M1.addNum(3);
    res = M1.findMedian();
    cout << res << endl;
    return 0;
}
/*
priority_queue<int,vector<int>,less<int>> maxheap;
priority_queue<int,vector<int>,greater<int>> minheap;*/