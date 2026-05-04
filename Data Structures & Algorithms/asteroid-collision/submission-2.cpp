class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        s.push(asteroids[0]);
        int i=1;

        while(i<asteroids.size()){
            if(!s.empty() && s.top()>0 && asteroids[i]<0){
                if(abs(s.top())<abs(asteroids[i])){
                    s.pop();
                }
                else if(abs(s.top())==abs(asteroids[i])) {
                    s.pop();
                    i++;
                }
                else {
                    i++;
                }
            }
            else{
                s.push(asteroids[i]);
                i++;
            }
        }

                vector<int> result;
        while(!s.empty()){
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};