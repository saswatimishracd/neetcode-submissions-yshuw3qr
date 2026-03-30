class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left = 0;
        unordered_set<int> window;
        for(int right=0;right<nums.size();right++){
            if(window.find(nums[right]) != window.end()){
                return true;
            }
            else{
                window.insert(nums[right]);
                if((right-left+1)>k){
                    window.erase(nums[left]);
                    left++;
                }
            }
        }
        return false;
    }
};