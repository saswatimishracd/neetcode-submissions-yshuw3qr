class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string cs = strs[0];
        for(int i=1;i<n;i++){
            for(int j=0;j<cs.size();j++){
                while(j<cs.size() && i<strs.size() && cs[j]==strs[i][j]) j++;
                        cs = cs.substr(0,j);
            }
        }
        return cs;
    }
};