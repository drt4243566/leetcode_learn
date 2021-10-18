#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int rollNum(int t){
    int res = 0;
    if(t>5) res = 9-t;
    else res = t;
    return res;
}

int leastStep(int targetNum,vector<int> trapNumArray,int trapNumCnt){
    vector<int> num_arr(3,0);
    int i=0;
    int sum = 0;
    unordered_set<int> set;
    while(targetNum>0){
        int t = targetNum%10;
        num_arr[i] = t;
        targetNum /= 10;
        sum += t;
    }
    for(int i=0;i<targetNum;i++){
        set.insert(trapNumArray[i]);
    }
    // 求后两位的步数和
    int last2Sum = rollNum(num_arr[1]+num_arr[2]);
    // 求首位的数字
    // 1为正序，2为倒序
    int Minsteps1 = 0,Minsteps2 = 0;
    for(int i=1;i<=num_arr[0];i++){
        int tempNum = 100*i+last2Sum;
        if(set.count(tempNum)){
            break;
        }
        Minsteps1++;
    }
    // 中途遇到空洞
    if(Minsteps1!=(num_arr[0])){
        for(int i=9;i>=num_arr[0];i--){
        int tempNum = 100*i+last2Sum;
        if(set.count(tempNum)){
            break;
        }
        Minsteps2++;
        }
    }
    if()
}

000 234 123  234