class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candy1=0,candy2=0,count1=0,count2=0;
        for(int num:nums){
            if(candy1==num) count1++;
            else if(candy2==num) count2++;
            else if(count1==0){
                candy1 = num;
                count1++;
            }
            else if(count2==0){
                candy2 = num;
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for(int num:nums){
            if(candy1==num) count1++;
            else if(candy2==num) count2++;
        }
        vector<int> result;
        if(count1>(n/3)) result.push_back(candy1);
        if(count2>(n/3)) result.push_back(candy2);
    return result;
    }
};