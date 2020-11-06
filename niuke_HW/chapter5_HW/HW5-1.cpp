#include <iostream>

using namespace std;

// 递归版本
int process(int x, int y)
{
    if (x == y)
    {
        return x;
    }
    else
    {
        // 内含特征，求当前节点的父节点直接除以2
        return x > y ? process(x / 2, y) : process(x, y / 2);
    }
}

// 非递归版本
int processUnRecur(int x, int y)
{
    while (x != y)
    {
        if (x > y)
        {
            x /= 2;
        }
        else
        {
            y /= 2;
        }
    }
    return x;
}

int main()
{
    int x, y;
    cin >> x >> y;
    cout << process(x, y) << endl;
    cout << processUnRecur(x, y) << endl;
    return 0;
}