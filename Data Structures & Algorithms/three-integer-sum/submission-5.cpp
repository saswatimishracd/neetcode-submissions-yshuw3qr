class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int j=i+1;
            int k=n-1;
            int sum=0;
            while(j<k){
               sum = nums[i]+nums[j]+nums[k];
               if(sum==0) {
                res.push_back({nums[i],nums[j],nums[k]});
                j++;k--;
                 while(j>0 && nums[j-1]==nums[j]) j++;
               while(k<n-1 && nums[k]==nums[k+1]) k--;
               }
               else if(sum>0) k--;
               else{
                j++;
               }
              
            }
        }
            return res;
    }
};
