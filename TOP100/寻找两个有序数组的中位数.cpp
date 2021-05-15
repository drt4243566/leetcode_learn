#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int m = nums2.size();
        // 保证数组1一定最短
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        // Ci相当于是第i个数组的割，LMaxi表示第i个数组割后的左元素，Rmini表示割后的右元素；
        int L1,L2,R1,R2,c1,c2,lo=0,hi=2*n;
        // 二分查找C1对应的位置
        while(lo<=hi){
            c1 = (lo+hi)/2;
            c2 = n+m-c1;
            // 人为插入虚拟值 [1,2,3] --> [#1#2#3#]
            L1 = (c1==0)?INT_MIN:nums1[(c1-1)/2];
            R1 = (c1==2*n)?INT_MAX:nums1[c1/2];
            L2 = (c2==0)?INT_MIN:nums2[(c2-1)/2];
            R2 = (c2==2*m)?INT_MAX:nums2[c2/2];
            // c1划分太靠右
            if(L1>R2) hi=c1-1;
            // c1划分太靠左
            else if(L2>R1) lo = c1+1;
            else break;
        }
        return (max(L1,L2)+min(R1,R2))/2.0;
    }
};
int main(){

}