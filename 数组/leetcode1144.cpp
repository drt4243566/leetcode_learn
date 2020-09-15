class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int len=nums.size();
        if(len<2){
            return 0;
        }
        int even(0),odd(0);
        for(unsigned i=0;i!=len;i++){
            int left=i-1>=0?nums[i-1]:INT_MAX;
            int right=i+1<len?nums[i+1]:INT_MAX;
            if(i%2==0){
                if(nums[i]>=left||nums[i]<=right){
                    even+=nums[i]-min(left,right)+1;
                }
            }
            else{
                if(nums[i]>=left||nums[i]<=right){
                    odd+=nums[i]-min(left,right)+1;
                }
            }
        }
        return min(odd,even);
        //首次提交
    }
};