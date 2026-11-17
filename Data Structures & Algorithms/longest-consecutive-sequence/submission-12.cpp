class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        unordered_set<int> st;
        unordered_map<int,int> mp;
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
                mp[nums[i]] = count;
            }
        }
        int maxLength = INT_MIN;
        for(auto it:mp){
            if(it.second>maxLength){
                maxLength = it.second;
            }
        }
        return maxLength;
    }
};
