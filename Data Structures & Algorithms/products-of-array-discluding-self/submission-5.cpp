class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        ans[0]=1; int prev=1;
        for(int i=1;i<n;i++){
            prev *= nums[i-1];
            ans[i]=prev;
        }
        int mul=1;
        for(int j=n-2;j>=0;j--){
            mul*=nums[j+1];
            ans[j] *= mul;
        }
        return ans;
    }
};
