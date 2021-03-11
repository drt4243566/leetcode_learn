#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// n个整数的无序数组，找到每个元素后面比它大的第一个数字，要求时间复杂度为O(N);
vector<int> find(vector<int>& num){
    int len=num.size();
    // 空数组返回空
    if(len==0) return {};
    // 单调栈的思想
    stack<int> notFind;  // 栈中存放num中还未找到符合条件的元素索引
    vector<int> res(len,-1); //存放结果，-1表示未找到
    int i=0;
    while(i<len){
        // 如果栈空，或者当前num元素不大于栈顶，将当前元素的索引压栈，索引后移
        if(notFind.empty()||num[i]<=num[notFind.top()]) notFind.push(i++);
        // 当发现有更大的数字，先将栈顶元素保存到结果，出栈后不更新i，继续比较
        else{
            res[notFind.top()]=num[i];
            notFind.pop();
        }
    }
    return res;
}

int main()
{
    vector<int> num = {1, 3, 2, 4, 99, 101, 5, 8};
    vector<int> res = find(num);
    for(auto i : res)
        cout << i << "  ";
 
    return 0;
}