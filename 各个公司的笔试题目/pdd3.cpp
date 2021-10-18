#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

struct Node{
    int key;
    int value;
    Node(int num1,int num2):key(num1),value(num2){}
    bool operator<(const Node* b){
        return this->value < b->value;
    }
};

int main(){
    int T=0;
    cin >> T;
    while (T--)
    {
        int N=0;
        cin >> N;
        unordered_set<int> mp;
        vector<vector<Node*>> array;
        array.resize(1000,vector<Node*>());
        int maxget = 0;
        int index=0;
        while(N--){
            int like=0,day=0;
            cin >> like >> day;
            Node* tmp = new Node(index,like);
            for(int i=0;i<day;i++){
                array[i].push_back(tmp);
            }
            index++;
        }
        for(int i=0;i<array.size();i++){
            if(array[i].empty()) continue;
            sort(array[i].begin(),array[i].end());
        }
        for(int i=array.size()-1;i>=0;i--){
            if(array[i].empty()) continue;
            for(int j=array[i].size()-1;j>=0;j--){
                if(mp.count(array[i][j]->key)) continue;
                else{
                    mp.insert(array[i][j]->key);
                    maxget += array[i][j]->value;
                    break;
                }
            }
        }
        cout << maxget << endl;
    }
    return 0;
}