class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(),1);
        vector<int> result(nums.size(),1);
        int prod = 1;
        for(int i=1;i<nums.size();i++){
            prod = prod * nums[i-1];
            result[i] = prod;
        }
        prod = 1;
        for(int i=nums.size()-2;i>=0;i--){
            prod = prod * nums[i+1];
            result[i] = prod*result[i];
        }
        return result;
    }
};
