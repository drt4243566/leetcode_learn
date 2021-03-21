#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n=0,dis_op=0;
    // 能用静态数组解决的，尽量用一下
    int nums[50];
    // 没有忽略之前的路径长度
    int ans = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> nums[i];
        if(i>0){
            ans += abs(nums[i]-nums[i-1]);
        }
    }
    // 忽略掉中间节点的意思是 A->B->C到A->C的优化
    for(int i=0;i<n-2;i++){
        dis_op = max(dis_op,abs(nums[i]-nums[i+1])+abs(nums[i+1]-nums[i+2])-abs(nums[i]-nums[i+2]));
    }
    printf("%d",ans-dis_op);
}