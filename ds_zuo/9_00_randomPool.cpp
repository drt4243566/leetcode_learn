#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

template<typename T>
class RandomPool {
private:
	unordered_map<T, int> keyIndexMap;
	unordered_map<int, T> indexKeyMap;
	size_t size;
public:
	RandomPool() {
		size = 0;
	}
	void insert(T key) {
		if (keyIndexMap.count(key)) {
			return;
		}
		keyIndexMap[key] = size;
		indexKeyMap[size] = key;
		size++;
	}
	void deletes(T key) {
		if (!keyIndexMap.count(key)) {
			return;
		}
		int deleteIndex = keyIndexMap[key];
        size--;
        int lastIndex = size;
        T lastKey = indexKeyMap[lastIndex];
        indexKeyMap[deleteIndex] = lastKey;
        keyIndexMap[lastKey] = deleteIndex;
        keyIndexMap.erase(key);
        indexKeyMap.erase(lastIndex);
    }
	T getRandom() {
		if (size == 0) {
			return T();
		}
		int r = rand() % size;
		return indexKeyMap[r];
	}
    void show(){
        cout<<"size: "<<size<<endl;
        for(auto p=keyIndexMap.begin();p!=keyIndexMap.end();p++){
            cout<<p->first<<":"<<p->second<<endl;
        }
        
        for(auto p=indexKeyMap.begin();p!=indexKeyMap.end();p++){
            cout<<p->first<<":"<<p->second<<endl;
        }
        cout<<""<<endl;
    }
};
int main() {
    RandomPool<char> t;
    t.insert('a');
    t.show();
    t.insert('b');
    t.show();
    t.insert('c');
    t.show();
    t.deletes('b');
    t.show();
    t.insert('b');
    t.show();
    for(int i=0;i<10;i++)
    cout<<t.getRandom();
	return 0;
}