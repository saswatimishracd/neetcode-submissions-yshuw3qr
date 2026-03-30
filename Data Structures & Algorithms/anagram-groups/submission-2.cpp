class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> result;
        for(auto s:strs){
            vector<int> freq(26,0);
            for(auto ch:s){
                freq[ch-'a']++;
            }
            string key = "";
            for(int i=0;i<freq.size();i++){
                key += freq[i]+'#';
            }
                mp[key].push_back(s);
        }
        for(auto it:mp){
            result.push_back(it.second);
        }
        return result;
    }
};
