class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s1;
        for(auto ch:tokens){
            if(ch=="+"){
                int val1=s1.top(); s1.pop();
                int val2=s1.top(); s1.pop();
                s1.push(val1+val2);
            }
            else if(ch=="-"){
                int val1=s1.top(); s1.pop();
                int val2=s1.top(); s1.pop();
                s1.push(val2-val1);
            }
            else if(ch=="*"){
                int val1=s1.top(); s1.pop();
                int val2=s1.top(); s1.pop();
                s1.push(val1*val2);
            }
            else if(ch=="/"){
                int val1=s1.top(); s1.pop();
                int val2=s1.top(); s1.pop();
                s1.push(val2/val1);
            }
            else s1.push(stoi(ch));
        }
        return s1.top();
    }
};
