class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size(),minLength=INT_MAX;
        int i=0,sum=0;
        if(n==0) return 0;
        for(int j=0;j<n;j++){
            sum += nums[j];
           while(sum>=target){
           minLength = min(minLength,j-i+1);
            sum -= nums[i];
            i++;
           } 
        }
   if(minLength==INT_MAX) return 0;
    return minLength;
    }
};