#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
void sortIntegerArray(vector<int>& pIntegerArray, int iSortFlag);
int comparator0(int a, int b);
int comparator1(int a, int b);

int main() {
	int arrSize(0);
	while (cin >> arrSize) {
		int sortFlag(0);         //排序标识：0表示按升序，1表示按降序
		int tempNum = 0;
		vector<int> arr;                                   //最好是每次循环都重新创建数组，避免奇怪的问题
		for (int i = 0; i < arrSize; i++) {
			cin >> tempNum;
			arr.push_back(tempNum);
		}
		cin >> sortFlag;
		//write code here
		sortIntegerArray(arr, sortFlag);
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] <<" ";                           //使用ends会报错，在连续输入的情况下
		}
		cout << endl;
	}
	return 0;
}

int comparator0(int a, int b) {       //升序比较器
	return a < b;
}
int comparator1(int a, int b) {       //降序比较器
	return a > b;
}
void sortIntegerArray(vector<int>&  pIntegerArray, int iSortFlag) {
	if(!iSortFlag)
		sort(pIntegerArray.begin(), pIntegerArray.end(), comparator0);
	else
		sort(pIntegerArray.begin(), pIntegerArray.end(), comparator1);
}