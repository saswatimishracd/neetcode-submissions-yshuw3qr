class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0,j=0;
        unordered_set<int> s;
        while(j<nums.size()){
           
            if(s.find(nums[j])!=s.end()){
                return true;
            }
            if(j-i+1>k) {
                s.erase(nums[i]);
                i++;
            }
            else{
                s.insert(nums[j]);
                j++;
            }

        }
        return false;
    }
};