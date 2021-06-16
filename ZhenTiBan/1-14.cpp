#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int cand=0;
        int HP=0;
        for(int i=0;i<numbers.size();i++){
            if(HP==0){
                cand = numbers[i];
                HP=1;
            }
            else if(cand==numbers[i]) HP++;
            else HP--;
        }
        HP=0;
        // 最好再加入一个验证环节
        /*for(int i=0;i<numbers.size();i++){
            if(numbers[i]==cand) HP++;
        }*/
        
        return cand;
    }
};