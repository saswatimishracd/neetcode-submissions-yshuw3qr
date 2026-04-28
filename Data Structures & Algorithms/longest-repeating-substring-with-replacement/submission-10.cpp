class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int n=s.size();
        int maxFreq = INT_MIN;
        int maxLen=INT_MIN;
        unordered_map<int,int> freq;
        for(int j=0;j<n;j++){       
            freq[s[j]-'A']++;
            maxFreq = max(maxFreq,freq[s[j]-'A']);
            while((j-i+1)-maxFreq > k){
                freq[s[i]-'A']--;
                i++;
            }
            maxLen = max(maxLen,(j-i+1));
        }
        return maxLen;
    }
};
