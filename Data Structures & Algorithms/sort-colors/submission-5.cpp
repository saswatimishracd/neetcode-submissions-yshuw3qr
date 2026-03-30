class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid=0;
        int low=0;
        int high=nums.size()-1;

        while(low<=mid && mid<=high){
            if(nums[mid]==2){ //whenever swapping 2 never increment mid
            swap(nums[mid],nums[high]);
            high--;
            }
            if(nums[mid]==0) {
               swap(nums[low],nums[mid]);
                    low++;mid++;
            }
            if(nums[mid]==1) mid++;
            
        }
    }
};