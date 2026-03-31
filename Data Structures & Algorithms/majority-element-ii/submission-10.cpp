class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int candidate1=nums[0],count1=1,candidate2=0,count2=0;
        for(int i=1;i<nums.size();i++){ 
                if(nums[i]==candidate1){
                    count1++;
                }else if(nums[i]==candidate2) {
                    count2++;
                }


                else if(count1==0){
                    candidate1=nums[i];count1++;
                }
               else if(count2==0){
                    candidate2=nums[i];count2++;
                }
               else{ if(count1>0)count1--;
                if(count2>0) count2--;
                  }
 
        }
        count1=0;
        count2=0;
        for(int num:nums){
            if(num==candidate1) count1++;
            else if(num==candidate2) count2++;
        } 
        vector<int> temp;
        if(count1>n/3) temp.push_back(candidate1);
        if(count2>n/3) temp.push_back(candidate2);
        return temp;
    }
};