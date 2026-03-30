class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> twoSum;
        for(int i=0;i<nums.size();i++){
            int search = target-nums[i];
            if(twoSum.find(search)!=twoSum.end()){
                return {twoSum[search],i};
            }  
            twoSum[nums[i]] = i;
        }
                return {};
    }
};
