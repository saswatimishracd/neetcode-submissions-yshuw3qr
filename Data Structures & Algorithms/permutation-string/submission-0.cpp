class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()) return false;

        vector<int> freq1(26,0), freq2(26,0);

        for(char c : s1)
            freq1[c-'a']++;

        int k = s1.size();
        int i = 0;

        for(int j = 0; j < s2.size(); j++) {

            freq2[s2[j]-'a']++;

            if(j - i + 1 > k){
                freq2[s2[i]-'a']--;
                i++;
            }

            if(freq1 == freq2)
                return true;
        }

        return false;
    }
};