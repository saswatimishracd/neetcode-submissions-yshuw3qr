class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(auto it:nums){
            s.insert(it);
        }
        int count;
        int maxFreq=1;
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            if(s.find(nums[i]-1) == s.end()){
                int temp=nums[i]+1;
                count=1;
                while(s.find(temp) != s.end()){
                    count++;
                    maxFreq = max(maxFreq,count);
                    temp++;
                }
            }
        }
        return maxFreq;
    }
};
