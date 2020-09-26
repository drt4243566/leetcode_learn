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
		int sortFlag(0);         //�����ʶ��0��ʾ������1��ʾ������
		int tempNum = 0;
		vector<int> arr;                                   //�����ÿ��ѭ�������´������飬������ֵ�����
		for (int i = 0; i < arrSize; i++) {
			cin >> tempNum;
			arr.push_back(tempNum);
		}
		cin >> sortFlag;
		//write code here
		sortIntegerArray(arr, sortFlag);
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] <<" ";                           //ʹ��ends�ᱨ������������������
		}
		cout << endl;
	}
	return 0;
}

int comparator0(int a, int b) {       //����Ƚ���
	return a < b;
}
int comparator1(int a, int b) {       //����Ƚ���
	return a > b;
}
void sortIntegerArray(vector<int>&  pIntegerArray, int iSortFlag) {
	if(!iSortFlag)
		sort(pIntegerArray.begin(), pIntegerArray.end(), comparator0);
	else
		sort(pIntegerArray.begin(), pIntegerArray.end(), comparator1);
}