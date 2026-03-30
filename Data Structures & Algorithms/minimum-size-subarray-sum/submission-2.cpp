class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,minLength=INT_MAX,sum=0;
        if(nums.size()==0) return 0;
        for(int right=0;right<nums.size();right++){
            sum += nums[right];
            while(sum>=target){
            minLength =  min(minLength,(right-left+1));
                sum -= nums[left];
                left++;
            }
        }
        if(minLength==INT_MAX) return 0;
        return minLength;
    }
};