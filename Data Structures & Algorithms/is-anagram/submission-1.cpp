class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> unique;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            unique[s[i]] += 1;
        }
        for(int j=0;j<t.size();j++){
            if(unique.find(t[j])!=unique.end()){
                unique[t[j]] -= 1;
            }
            if(unique[t[j]]==0) unique.erase(t[j]);
        }
        if(unique.empty()) return true;
        return false;
    }
};
