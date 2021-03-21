#include <iostream>
using namespace std;
#include <vector>
/*
对于一个无序数组A，请设计一个算法，求出需要排序的最短子数组的长度。

给定一个整数数组A及它的大小n，请返回最短子数组的长度。
*/
class ShortSubsequence {
public:
    int findShortest(vector<int> A, int n) {
        int maxIndex = -1;
        int minIndex = A.size();
        int max = A[0];
        int min = A[A.size()-1];
        for(int i = 0;i<A.size();i++){
            if(A[i]>=max){
                max = A[i];
            }else{
                maxIndex = i;
            }
        }
        for(int i = A.size()-1;i>=0;i--){
            if(A[i]<=min){
                min = A[i];
            }else{
                minIndex = i;
            }
        }
        cout<<maxIndex <<minIndex<<endl;
        if(maxIndex == -1)return 0;
        return maxIndex - minIndex +1;
    }
};

int main(){

    vector<int> A{1,2,10,1,8,9};
    ShortSubsequence S;
    S.findShortest(A,6);
}