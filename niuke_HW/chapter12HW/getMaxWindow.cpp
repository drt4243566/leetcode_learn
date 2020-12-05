#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#define ARRAY_SIZE(ARRAY) (sizeof(ARRAY) / sizeof(ARRAY[0]))
// 对指针使用这一套容易出问题
// 这一套在vs2019才能运行
using namespace std;

int *getMaxWindow(int arr[], int arrSize, int w)
{
    if (arrSize < w || w < 1 || arr == NULL)
    {
        return NULL;
    }
    deque<int> qmax;                     // deque里存放的是数组索引值
    int *res = new int[arrSize - w + 1]; //不能用变量直接创建数组，使用new
    int index = 0;
    for (int i = 0; i < arrSize; i++)
    {
        //R右移
        while (!qmax.empty() && arr[qmax.back()] <= arr[i])
        {
            qmax.pop_back();
        }
        qmax.push_back(i);
        //L右移（当i<w-1时，不会触发）
        if (qmax.front() == i - w)
        {
            qmax.pop_front();
        }
        //将max写入res
        if (i >= w - 1)
        {
            res[index++] = arr[qmax.front()];
        }
    }
    return res;
}

vector<vector<int> > getNearless(int arr[], int arrSize)
{
    if (arr == NULL || arrSize < 2)
    {
        vector<vector<int> > erro = {{-1, -1}};
        return erro;
    }
    stack<deque<int> > stack;
    vector<vector<int> > res(arrSize, vector<int>(2));
    //int(*res)[2] = new int[arrSize][2]; //c++二维数组动态分配
    for (int i = 0; i < arrSize; i++)
    {
        // 得到最近最小值，栈要保证从小到大
        while (!stack.empty() && arr[i] < arr[stack.top().front()])
        {
            deque<int> temp = stack.top();
            stack.pop();
            int leftlessIndex = stack.empty() ? -1 : stack.top().back();
            for (int j : temp)
            {
                res[j][0] = leftlessIndex;
                res[j][1] = i;
            }
        }
        if (!stack.empty() && arr[i] == arr[stack.top().front()])
        {
            stack.top().push_back(i);
        }
        else
        {
            deque<int> bigNum;
            bigNum.push_back(i);
            stack.push(bigNum);
        }
    }
    // 遍历完成后，栈还有剩余元素
    while (!stack.empty())
    {
        deque<int> temp = stack.top();
        stack.pop();
        int leftlessIndex = stack.empty() ? -1 : stack.top().back();
        for (int j : temp)
        {
            res[j][0] = leftlessIndex;
            res[j][1] = -1;
        }
    }
    return res;
}

int main()
{
    int a[] = {5, 6, 3, 2};
    int aSize = ARRAY_SIZE(a);
    int *res = getMaxWindow(a, aSize, 2);
    for (int i = 0; i < aSize - 1; i++)
    {
        printf("%d ", res[i]);
    }
    vector<vector<int> > result = getNearless(a, aSize);
    
    return 0;
}