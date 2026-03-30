class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s(nums.begin(),nums.end());
        int maxFreq=1;
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            if(s.find(nums[i]-1) == s.end()){
                int temp=nums[i]+1;
                int count=1;
                while(s.find(temp) != s.end()){
                    count++;
                    temp++;
                }
                maxFreq = max(maxFreq,count);
            }
        }
        return maxFreq;
    }
};
