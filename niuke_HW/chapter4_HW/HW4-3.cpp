#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int count = n + 1;
		vector<int> num;
		for (int i = 0; i < count; i++)
			num.push_back(i);
		while (count != 1) // 最终必然剩下两个数字，序号为0和1
		{
			int index = 0;
			while (2 * index + 1 < count)
			{ // 注意这里的count实际上是n+1，所以要用 <
				num[index] = num[2 * index + 1];
				index++; //不要忘记这里的递增运算符
			}
			count = index;
		}
		cout << num[0] << endl; //这里输出0和1位置皆可，由于当count=2或者3的时候，0位置经过运算已经等于1位置的数字
	}
	return 0;
}
