class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,maxLength = INT_MIN,maxFreq=INT_MIN;
        unordered_map<int,int> window;
        for(int right=0;right<s.size();right++){
                window[s[right]-'A']++;        
            maxFreq = max(maxFreq,window[s[right]-'A']);
            while((right-left+1)-maxFreq>k){
                window[s[left]-'A']--;
                left++;
            }
            maxLength = max(maxLength,(right-left+1));          
        }
        return maxLength;
    }
};
