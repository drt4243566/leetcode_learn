#include <iostream>
#include <string>
#include <list>
#include <sstream>
using namespace std;
class StringEdit {
private:
	list<char> lst;
	stringstream cmd;
	list<char>::iterator iter;
	list<char>::iterator p;
public:
	StringEdit(list<char> s, string& c) {
		lst = list<char>(s.begin(), s.end());
		cmd = stringstream(c);
		iter = lst.begin();
	}
	void start() {
		char now;
		while (cmd >> now) {
			switch (now) {
			case 'i':
				if (cmd.eof())break;
				cmd >> now;
				if (now == 'e') break;
				else {
					iter = lst.insert(iter, now);
					++iter;
				}
				//cout<<"i:"<<endl;
				//show();
				break;
			case 'f':
				if (cmd.eof())break;
				cmd >> now;
				p = iter;
				while (p != lst.end()) {
					p++;
					if (*p == now) {
						iter = p;
						break;
					}
				}
				//cout<<"f:"<<endl;
				//show();
				break;
			case 'x':
				iter = lst.erase(iter);
				//cout<<"x:"<<endl;
				//show();
				break;
			case 'h':
				if (iter == lst.begin())break;
				else iter--;
				//cout<<"h:"<<endl;
				//show();
				break;
			case 'l':
				if (iter == lst.end())break;
				else iter++;
				//cout<<"l:"<<endl;
				//show();
				break;
			}
		}
	}
	void show() {
		int num = 1;
		for (auto ps = lst.begin(); ps != lst.end(); ps++) {
			cout << *ps;
		}
		for (auto ps = lst.begin(); ps != iter; ps++) {
			if (ps != iter) {
				num++;
			}
		}
		//cout<<"  :"<<num<<endl;
	}

};
int main() {
	string cmd;
	list<char> lst;
	char ch;
	while (ch = getchar(), ch != '\n') {
		lst.push_back(ch);
	}
	while (ch = getchar(), ch != '\n') {
		cmd += ch;
	}
	StringEdit S(lst, cmd);
	S.start();
	S.show();
	system("pause");
	return 0;
}