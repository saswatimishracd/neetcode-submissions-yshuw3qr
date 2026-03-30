class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size();
        if(n!=t.size()) return false;
        unordered_map<int,int> mp;
        for(char ch:s){
            mp[ch]++;
        }
        for(char ch:t){
            mp[ch]--;
            if(mp[ch]==0) mp.erase(ch);
        }
        if(mp.empty()) return true;
        else return false;
    }
};
