class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int a=0;a<n;a++){
            if(a>0 && nums[a-1]==nums[a]) continue;
            for(int b=a+1;b<n;b++){
                if(b>a+1 && nums[b-1]==nums[b]) continue;
                int c=b+1,d=n-1;
                while(c<d){
                    long long sum = (long long) nums[a]+nums[b]+nums[c]+nums[d];
                    if(sum==target){
                        res.push_back({nums[a],nums[b],nums[c],nums[d]});
                        c++;d--;
                        while(c<n && nums[c-1]==nums[c]) c++;
                        while(d<n && nums[d]==nums[d+1]) d--;
                    }
                    else if(sum>target) d--;
                    else c++;
                }
            }
        }
        return res;
    }
};