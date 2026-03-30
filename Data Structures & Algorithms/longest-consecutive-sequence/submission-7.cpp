class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int maxLength = 1;
        unordered_set<int> s(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int count = 0;
            if(s.find(nums[i]-1)!=s.end()) continue;
            else{
                count++;
                int temp = nums[i]+1;
                while(s.find(temp)!=s.end()){
                    count++;
                    maxLength = max(maxLength,count);
                    temp++;
                }
            }
        }
        return maxLength;
    }
};
