class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char a:s){
            if(st.empty()) st.push(a);
            else if(!st.empty()){
                if(st.top()=='(' && a==')') st.pop();
                else if(st.top()=='{' && a=='}') st.pop();
                else if(st.top()=='[' && a==']') st.pop();
                else st.push(a);
            }
        }
        return st.empty();
    }
};
