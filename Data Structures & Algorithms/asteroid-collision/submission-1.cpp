class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        s.push(asteroids[0]);
        int i = 1;
        while (i < asteroids.size()) {
            if (!s.empty() && s.top() > 0 && asteroids[i] < 0) {  // only collide when moving toward each other
                if (abs(s.top()) < abs(asteroids[i])) {
                    s.pop();
                    continue;
                } else if (abs(s.top()) == abs(asteroids[i])) {
                    s.pop();
                    i++;
                } else {  // s.top() wins, current asteroid destroyed
                    i++;
                }
            } else {
                s.push(asteroids[i]);
                i++;
            }
        }
        vector<int> result;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(), result.end());  // fix reversed order
        return result;
    }
};