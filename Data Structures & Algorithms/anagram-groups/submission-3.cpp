class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string,vector<string>> mp;
      for(int i=0;i<strs.size();i++){
        vector<int> freq(26,0);
        string key = "";
        for(int j=0;j<strs[i].size();j++){
            freq[strs[i][j]-'a']++;
        }
        for(int i=0;i<26;i++){
            key += freq[i]+'#';
        }
        if(mp.find(key)!=mp.end()) {
            mp[key].push_back(strs[i]);
        }
        else{
            mp[key] = {strs[i]};
        }
      } 
      vector<vector<string>> result;
      for(auto it:mp){
        result.push_back(it.second);
      } 
      return result;
    }
};
