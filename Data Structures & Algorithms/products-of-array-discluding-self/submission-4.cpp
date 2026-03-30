class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n);
        presum[0] = 1;
        for(int i=1;i<n;i++){
            presum[i] = presum[i-1]*nums[i-1];
        }
        int suffix = 1;
        for(int j=n-1;j>=0;j--){
            presum[j] *= suffix;
            suffix *= nums[j];
        }
        return presum;
    }
};
