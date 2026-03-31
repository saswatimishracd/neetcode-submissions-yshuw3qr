class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(),count=0,maxLength=0;
        unordered_set<int> st(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            count=0;
            if(st.find(nums[i]-1) == st.end()){
                int temp=nums[i]-1;
                while(st.find(temp+1)!=st.end()){
                    count++;
                    temp++;
                }
            }
            else{
                continue;
            }
            maxLength = max(maxLength,count);
        }
        return maxLength;
    }
};
