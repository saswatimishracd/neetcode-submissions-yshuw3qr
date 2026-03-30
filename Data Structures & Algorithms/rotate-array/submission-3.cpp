class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int n=nums.size();
         int rotNum = k%n;
         if(rotNum == 0) return;
         reverse(nums.begin(),nums.end());
         reverse(nums.begin(),nums.begin()+rotNum);
         reverse(nums.begin()+rotNum,nums.end());
         return;
        }
};