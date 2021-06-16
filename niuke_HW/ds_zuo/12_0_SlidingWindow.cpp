#include <iostream>
#include <deque>
#include <vector>
using namespace std;
class SlidingWindow {
	vector<int> arr;
	deque<int> qmax;
	int windowSize;
public:
	SlidingWindow(vector<int> &v, int w) {
		arr = v;
		windowSize = w;
	}
	vector<int> getWindowMax() {
        vector<int> res;
		if(arr.size()<windowSize){
            return res;
        }
        int index = 0;
        for(int i = 0; i < arr.size(); i++){
            while(!qmax.empty() && arr[qmax.back()] <= arr[i]){
                qmax.pop_back();
            }
            qmax.push_back(i);
            if(qmax.front() == i - windowSize){
                qmax.pop_front();
            }
            if(i >= windowSize - 1){
                res.push_back(arr[qmax.front()]);
            }
        }
        return res;
	}
    void show() {
		cout << "left:" << left << " right:" << right << endl;
		for (auto p = qmax.begin(); p != qmax.end(); p++) {
			cout << *p << " ";
		}
		cout << endl;
        cout << endl;
	}
};
int main() {
	vector<int> v{ 4,3,5,4,3,3,6,7 };
	SlidingWindow T(v, 3);
    vector<int> res = T.getWindowMax();
    for(auto p = res.begin(); p!= res.end(); p++){
        cout<<*p<<endl;
    }
	return 0;
}
