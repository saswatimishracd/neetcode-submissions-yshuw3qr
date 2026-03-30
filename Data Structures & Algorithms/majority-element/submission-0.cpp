class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            if(freq.find(nums[i])!=freq.end()){
                if(freq[nums[i]]>(nums.size()/2)){
                    return nums[i];
                }
            }
        }
        return 0;
    }
};