#include"HW3-2.h"

using namespace std;

int main() {
	Solution1 sol;
	int InputSize = 0;
	while (cin>> InputSize)
	{
		int start(0), end(0);
		vector<Interval> AllInterval, Res;       //ÿ�ζ�Ҫ���õ�����Ӧ����whileѭ���ڲ�

		for (int i = 0; i < InputSize; i++) {
			cin >> start >> end;
			Interval InputInterval(start,end);
			AllInterval.push_back(InputInterval);
		}
		cin >> start >> end;
		Interval NewIntrval(start, end);
		Res = sol.insert(AllInterval, NewIntrval);

		for (auto j : Res) {
			cout << j.start << " " << j.end<<" ";
		}
		cout << endl;
	}
	return 0;
}