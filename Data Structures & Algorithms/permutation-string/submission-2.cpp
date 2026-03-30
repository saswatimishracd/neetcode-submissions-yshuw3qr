class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        if(n1>n2) return false;
        for(int k=0;k<n1;k++){
            freq1[s1[k]-'a']++;
        }
        int i=0;
        for(int j=0;j<n2;j++){
            freq2[s2[j]-'a']++;
            while(j-i+1>n1){
                freq2[s2[i]-'a']--;
                i++;
            }
            if(freq1==freq2) return true;
        }
        return false;
    }
};
