class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
            int freq1 = 0;
            int freq2 = 0;
            int count2 = 0;
            int count1 = 0;
            if(nums.size()==0) return {};
        for(int i=0;i<nums.size();i++){
            if(freq1==nums[i]) count1++;
            else if(freq2==nums[i]) count2++;
            else if(count1==0){
                freq1 = nums[i];
                count1++;
            }
            else if(count2==0){
                freq2 = nums[i];
                count2++;
            }
            
            else if(count1!=0 && count2!=0){
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int it:nums){
            if(it==freq1){
                count1++;
            }
            else if(it==freq2){
                count2++;
            }
        }
        vector<int> result;
        if(count1>nums.size()/3) result.push_back(freq1);
        if(count2>nums.size()/3) result.push_back(freq2);
        return result;
    }
};