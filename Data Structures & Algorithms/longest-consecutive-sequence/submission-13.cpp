class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int maxLength = INT_MIN;
        unordered_set<int> st;
        for(int it:nums){
            st.insert(it);
        }
        for(int i=0;i<n;i++){
            if(st.find(nums[i]-1)==st.end()){
                int count = 1;
                int temp = nums[i]+1;
                while(st.find(temp) != st.end()){
                    count++;
                    temp++;
                }
                if(count>maxLength){
                    maxLength = count;
                }
            }
        }
        return maxLength;
    }
};
