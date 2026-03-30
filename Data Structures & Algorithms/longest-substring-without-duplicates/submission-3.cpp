class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left=0,maxLength=INT_MIN;
        if(s.size()==0) return 0;
        for(int right=0;right<s.size();right++){
            while(st.find(s[right]) != st.end()){
                 st.erase(s[left]);
            left++;
               
            }
           
            maxLength = max(maxLength,right-left+1);
             st.insert(s[right]);
        }
            return maxLength;
    }
};
