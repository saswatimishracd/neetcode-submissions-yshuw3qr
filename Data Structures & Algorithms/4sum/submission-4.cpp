class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> result;
        for(int a=0;a<n;a++){
        if(a>0 && nums[a-1]==nums[a]) continue;
        for(int i=a+1;i<n;i++){
            int j=i+1,k=n-1;
            if(i>a+1 && nums[i-1]==nums[i]) continue;
            while(j<k){
                long long sum=(long long)nums[a]+nums[i]+nums[j]+nums[k];
                if(sum==target){
                    result.push_back({nums[a],nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<n && nums[j]==nums[j-1]) j++;
                    while(j<n && nums[k]==nums[k+1]) k--;
                }else if(sum<target) j++;
                else k--;             
            }
          }
        }
            return result;
    }
};