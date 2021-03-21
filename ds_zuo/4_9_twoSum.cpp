#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& numbers, int target){
        unordered_map<int,int> hashTable;
        int i;
        for(i=1; i<=numbers.size(); i++){
            hashTable[numbers[i-1]] = i;
        }
        int temp;
        for(i=1; i<numbers.size(); i++){
            temp = target - numbers[i-1];
            if(hashTable.find(temp) != hashTable.end()){
                if(hashTable[temp] != i)
                    break;
            }
        }
        return vector<int>{i,hashTable[temp]};
    }
};

int main(){

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(9);
    v.push_back(13);
    v.push_back(30);
    Solution s;
    vector<int> w = s.twoSum(v,14);
    cout<<w[0]<<w[1]<<endl;
    return 0;
}