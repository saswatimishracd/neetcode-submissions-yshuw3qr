class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int left = 0;
        int right = nums.size() - 1;
        if(nums.size()==1){
            if(nums[0]==target) return true;
            else return false;
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                    return true;
            
            if(nums[left] == nums[mid] && nums[mid] == nums[right]){
                if(left<n) left++;
                if(right>0) right--;
            }
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] <= nums[right]) {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
    }
        return false;
    
}
};