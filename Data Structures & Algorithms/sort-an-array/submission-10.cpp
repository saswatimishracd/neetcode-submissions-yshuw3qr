class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<n-i;j++){
                if(nums[j]<nums[j-1]){
                    swap(nums[j],nums[j-1]);
                }
            }
        }
        return nums;
    }
};