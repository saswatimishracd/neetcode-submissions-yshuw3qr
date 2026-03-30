class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        int n=max(n1,n2);
        int i=0,j=0;
        string res;
        while(i<n1 && j<n2){
            res.push_back(word1[i]);
            res.push_back(word2[j]);
            i++;j++;
        }
        while(i<n1){
            res.push_back(word1[i]);
            i++;
        }
        while(j<n2){
            res.push_back(word2[j]);
            j++;
        }
        return res;
    }
};