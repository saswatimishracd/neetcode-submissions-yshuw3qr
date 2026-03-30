class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,maxLength=INT_MIN;
        unordered_set<char>st;
        if(s.size()==0) return 0;
        for(int j=0;j<s.size();j++){
            while(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }
            maxLength = max(maxLength,(j-i+1));
            st.insert(s[j]);
        }
        return maxLength;
    }
};
