class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char p : s) {
            if(p == '(' || p == '{' || p == '[') {
                st.push(p);
            } 
            else {
                if(st.empty()) return false;

                if((p == ')' && st.top() != '(') ||
                   (p == '}' && st.top() != '{') ||
                   (p == ']' && st.top() != '[')) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};