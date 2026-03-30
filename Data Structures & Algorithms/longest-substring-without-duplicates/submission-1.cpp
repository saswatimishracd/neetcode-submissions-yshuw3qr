class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        unordered_set<char> window;
        int maxLength = INT_MIN;
        if(s.size()==0) return 0;
        for(int right=0;right<s.size();right++){
            while(window.find(s[right])!=window.end()){
                window.erase(s[left]);
                left++;
            }
            maxLength = max(maxLength,right-left+1);
            window.insert(s[right]);
        }
        return maxLength;
    }
};
