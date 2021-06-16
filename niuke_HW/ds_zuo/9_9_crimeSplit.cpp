#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct node{
    int x;
    int y;
    int nu;
};
bool com(node n1, node n2){
    return n1.nu > n2.nu;
}
class UnionFindSet {
private:
	unordered_map<int, int> elementMap;
	unordered_map<int, int> fatherMap;
	unordered_map<int, int> sizeMap;
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

    int N, M;
    cin>>N>>M;
    vector<node> v;
    node n1;
    for(int i=0;i<M;i++){
        cin>>n1.x>>n1.y>>n1.nu;
        v.push_back(n1);
    }
    sort(v.begin(),v.end(),com);
    vector<int> vt;
    for(int i=1;i<=N*2;i++){
        vt.push_back(i);
    }
    UnionFindSet u(vt);
    for(auto p=v.begin();p!=v.end();p++){
        if(u.isSameSet(p->x, p->y)){
            cout<<p->nu<<endl;
            return 0;
        }
        u.unions(p->x, p->y + N);
        u.unions(p->y, p->x + N);
    }
    cout<<0<<endl;
	return 0;
}

