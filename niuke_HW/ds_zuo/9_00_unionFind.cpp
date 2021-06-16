#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

class UnionFindSet {
private:
	unordered_map<int, int> elementMap;  // 自己节点
	unordered_map<int, int> fatherMap;   // 父节点
	unordered_map<int, int> sizeMap;     // 头节点下属的元素个数
	int findHead(int temp) {
		stack<int> path;
		while (temp != fatherMap[temp]) {
			path.push(temp);
			temp = fatherMap[temp];
		}
		while (!path.empty()) {
			fatherMap[path.top(), temp];
			path.pop();
		}
		return temp;
	}
public:
	UnionFindSet(vector<int> v) {
		for (auto p = v.begin(); p != v.end(); p++) {
			int temp = *p;
			elementMap[temp] = temp;
			fatherMap[temp] = temp;
			sizeMap[temp] = 1;
		}
	}
	// 查询两个数是否在同一个集合
	bool isSameSet(int a, int b) {
		if (elementMap.count(a) && elementMap.count(b)) {
			return findHead(elementMap[a]) == findHead(elementMap[b]);
		}
		return false;
	}
	void unions(int a, int b) {
		if (elementMap.count(a) && elementMap.count(b)) {
			int aF = findHead(elementMap[a]);
			int bF = findHead(elementMap[b]);
			if (aF != bF) {
				int big = sizeMap[aF] >= sizeMap[bF] ? aF : bF;
				int small = big == aF ? bF : aF;
                fatherMap[small] = big;
				sizeMap[big] = sizeMap[aF] + sizeMap[bF];
				sizeMap.erase(small);
			}
		}
	}
};
int main() {

	vector<int> v{ 1,2,3,4,5,6,7,8 };
	UnionFindSet u(v);
	cout << u.isSameSet(1, 2)<<endl;
    u.unions(1,2);
    cout<<u.isSameSet(1,2)<<endl;
    u.unions(2,3);
    cout<<u.isSameSet(3,1)<<endl;
	system("pause");
	return 0;
}

/*
struct element{
	int value;
	int operator==(element temp){
		return value==temp.value;
	}
};
class UnionFindSet{
private:
	unordered_map<int,element> elementMap;
	unordered_map<element,element> fatherMap;
	unordered_map<element,int> sizeMap;
	element findHead(element temp){
		stack<element> path;
		while(!(temp==fatherMap[temp])){
			path.push(temp);
			temp = fatherMap[temp];
		}
		while(!path.empty()){
			fatherMap[path.top(),temp];
			path.pop();
		}
		return temp;
	}
public:
	UnionFindSet(vector<int> v){
		element temp;
		for(auto p = v.begin();p!=v.end();p++){
			temp.value = *p;
			elementMap[*p] = temp;
			fatherMap[temp] = temp;
			sizeMap[temp] = 1;
		}
	}
	bool isSameSet(int a, int b){
		if(elementMap.count(a) && elementMap.count(b)){
			return findHead(elementMap[a]) == findHead(elementMap[b]);
		}
		return false;
	}
	void unions(int a, int b){
		if(elementMap.count(a) && elementMap.count(b)){
			element aF = findHead(elementMap[a]);
			element bF = findHead(elementMap[b]);
			if(!(aF == bF)){
				element big = sizeMap[aF]>=sizeMap[bF]?aF:bF;
				element small = big == aF?bF:aF;
				sizeMap[big] = sizeMap[aF]+sizeMap[bF];
				sizeMap.erase(small);
			}
		}
	}
};
*/