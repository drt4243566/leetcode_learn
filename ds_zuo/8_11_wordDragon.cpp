#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int N;
vector<string> words;
char start;
string connect(string preDragon, string back, int num) {
	return preDragon.substr(0, preDragon.size() - num) + back;
}

int isconnect(string preDragon, string back) {
	int maxL = min(preDragon.size() - 1, back.size() - 1);
	int dragonSize = preDragon.size();
	for (int i = 0; i < maxL; i++) {
		int b = preDragon.substr(dragonSize - maxL + i, maxL - i) == back.substr(0, maxL - i);
		if (b) {
			return maxL - i;
		}
	}
	return 0;
}
int contain(string str1, string str2) {
	int L1 = str1.size();
	int L2 = str2.size();
	if (L2 > L1)return 0;
	if (str1.substr(L1 - L2, L2) == str2) {
		return 1;
	}
	return 0;
}
int isconnect2(string preDragon, string back) {
	int size1 = preDragon.size();
	int size2 = back.size();
	int size = 0;
	for (int i = 0; i < min(size1,size2); i++) {
		if (preDragon[size1 - 1] == back[i]) {
			for (int j = size1 - 1, k = i; j >= 0 && k >= 0; j--, k--) {
				if (preDragon[j] != back[k]) {
					return 0;
				}
			}
			size = i + 1;
			break;
		}
	}
	return size;
}
void process(string dragon, vector<int> visit, priority_queue<int> &res) {
	//int flag1 = 0;
	int flag2 = 0;
	for (int i = 0; i < N; i++) {
		if (visit[i] < 2) {
			//flag1 = 1;
			//cout<<dragon<<" "<<words[i]<<endl;
			//cout << "visit: " << words[i] << " visit=" << visit[i] << endl;
			int num = isconnect2(dragon, words[i]);
			if (num == words[i].size())num = 0;
			//cout<<"out"<<endl;
			if (num) {
				flag2 = 1;
				vector<int> tempv = visit;
				tempv[i]++;
				cout << endl;
				for (int k = 0; k < visit.size(); k++) {
					cout << words[k] << " visit:" << visit[k] << " ";
				}
				cout << endl;
				cout << "connect:" << dragon << "," << words[i] << ","<<num<<endl;
				string temp = connect(dragon, words[i], num);
				cout << "yesnect:"<<temp << endl;
				process(temp, tempv, res);
				//cout<<visit[i]<<" ";
			}

		}
	}
	if (flag2 == 0) {
		cout << "out --------->end:" << dragon << " size:"<<dragon.size()<<endl;
		res.push(dragon.size());
		//cout<<dragon<<endl;
	}
}
int wordDragon(vector<int> visit) {
	if (N <= 0) {
		return 0;
	}
	priority_queue<int> res;
	for (int i = 0; i < N; i++) {
		if (words[i][0] == start and visit[i] < 2) {
			visit[i]++;
			cout << "enter-->" << words[i] << endl;
			process(words[i], visit, res);
		}
	}
	if (res.empty()) {
		return 0;
	}
	else {
		return res.top();
	}
}

int main() {
	///*
	cin >> N;
	vector<int> visit;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		words.push_back(temp);
		visit.push_back(0);
	}
	cin >> start;
	cout << wordDragon(visit) << endl;
	system("pause");
	//*/
	//cout<<isconnect2("abababcdababa", "abababc");
	cin.get();
	return 0;
}
