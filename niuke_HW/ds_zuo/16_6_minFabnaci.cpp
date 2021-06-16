#include <iostream>
#include <vector>
using namespace std;

int main() {
	int num;
	cin >> num;
	vector<int> arr{ 0,1,1 };
	while (arr[arr.size() - 1] < num) {
		int len = arr.size();
		arr.push_back(arr[len - 2] + arr[len - 1]);
	}
	cout << min(arr[arr.size() - 1] - num, num - arr[arr.size() - 2]) << endl;

	return 0;
}