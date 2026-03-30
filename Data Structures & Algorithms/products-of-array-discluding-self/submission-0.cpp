class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size()),suffix(nums.size());
        int prod=1;
        prefix[0]=1;
        for(int i=1;i<nums.size();i++){
            prod=prod*nums[i-1];
            prefix[i]=prod;
        }
        int prod2=1;
        suffix[nums.size()-1]=1;
        for(int j=nums.size()-2;j>=0;j--){
            prod2 *= nums[j+1];
            suffix[j]=prod2;
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            res.push_back(prefix[i]*suffix[i]);
        }
    return res;
    }
};
