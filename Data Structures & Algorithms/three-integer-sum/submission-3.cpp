class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            if(i>0 && nums[i-1]==nums[i]) continue;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    result.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<n && nums[j-1]==nums[j]) j++;
                    while(j<n && nums[k]==nums[k+1]) k--;
                }else if(sum<0) j++;
                else k--;             
            }
        }
            return result;
    }
};
