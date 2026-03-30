class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,maxLength=INT_MIN,maxFreq=INT_MIN;
        unordered_map<int,int> freq;
        for(int j=0;j<s.size();j++){
            freq[s[j]-'A']++;
            maxFreq = max(maxFreq,freq[s[j]-'A']);
            while((j-i+1)-maxFreq>k){
                freq[s[i]-'A']--;
                i++;
            }
            maxLength = max(maxLength,(j-i+1));
        }
        return maxLength;
    }
};
