class Solution {
public:

    int binarySearch(int left,int right,vector<int>& nums,int target){
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                return binarySearch(left,mid-1,nums,target);
            }
            else {
                return binarySearch(mid+1,right,nums,target);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(0,nums.size()-1,nums,target);
    }
};
