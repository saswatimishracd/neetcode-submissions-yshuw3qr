class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate1 = nums[0],count1=1,candidate2=0,count2=0;
        vector<int> result;
        for(int i=1;i<n;i++){
            if(candidate1==nums[i]) count1++;
            else if (candidate2==nums[i]) count2++;
            else if (count1==0) {
                candidate1 = nums[i];
                count1 = 1;
            }
            else if(count2==0){
                candidate2 = nums[i];
                count2 = 1;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0;count2=0;
        for(auto it:nums){
            if(it==candidate1) count1++;
            else if(it==candidate2) count2++;
        }
        if(count1>n/3) result.push_back(candidate1);
        if(count2>n/3) result.push_back(candidate2);
        return result;
    }
};