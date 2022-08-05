#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int singleRotate(int a){
    if(a==0 || a==1 ||a==8) return a;
    else if(a==6) return 9;
    else if(a==9) return 6;
    else return -1;
}

bool fanzhuan(int num){
    unordered_map<int,int> dic;
    dic[0] = 0;
    dic[1] = 1;
    dic[8] = 8;
    dic[9] = 6;
    dic[6] = 9;

    int num_old = num;
    int num_new = 0;
    int step = 0;
    while(num>0){
        int n = num%10;
        if(dic.count(n)==0){
            return false;
        }
        num /= 10;
        num_new = num_new*10 + dic[n];
    }
    return num_old==num_new;

    //1881 1



    for(int i=0;i<numbers.size();i++){
        int temp = numbers[i];
        if(singleRotate(temp)>=0){
            Rotate_numbers[i] = singleRotate(temp);
        }else{
            return false;
        }
    }
    for(int j=0;j<numbers.size();j++){
        if(numbers[j]!=Rotate_numbers[j]){
            return false;
        }
    }
    return true;
}

int main(){

    return 0;
}

0 1 8
/*
6 9
8 8
2
68 89
11 11 
*/
0 - 0
1 - 1
6 - 9
8 - 8
9 - 6

123
111