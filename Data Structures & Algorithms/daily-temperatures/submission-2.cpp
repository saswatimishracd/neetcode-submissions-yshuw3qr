class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> s;
        vector<int> result(n,0);

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && temperatures[i]>=temperatures[s.top()]){
                s.pop();
            }
            if(!s.empty()) {
                result[i]=s.top()-i;
            }
            else{
                result[i]=0;
            }
            s.push(i);
        }
        return result;
    }
};
