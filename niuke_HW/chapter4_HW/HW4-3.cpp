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
		while (count != 1) // ���ձ�Ȼʣ���������֣����Ϊ0��1
		{
			int index = 0;
			while (2 * index + 1 < count)
			{ // ע�������countʵ������n+1������Ҫ�� <
				num[index] = num[2 * index + 1];
				index++; //��Ҫ��������ĵ��������
			}
			count = index;
		}
		cout << num[0] << endl; //�������0��1λ�ýԿɣ����ڵ�count=2����3��ʱ��0λ�þ��������Ѿ�����1λ�õ�����
	}
	return 0;
}
