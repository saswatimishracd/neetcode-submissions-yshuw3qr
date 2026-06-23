class Solution {
public:
    string simplifyPath(string path) {
        stack <string> st;
        string token="";
    for(char ch:path){
    if(ch=='/'){
        if(token.empty() || token == ".") {

        }
        else if(token==".."){
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            st.push(token);
        }
        token.clear();
    }

    else{
        token += ch;
    }
    }

    if(!token.empty()){
        if(token==".."){
            if(!st.empty()){
                    st.pop();
                }
            token.clear();
            }
            else if(token=="."){
                token.clear();
            }
            else{
                st.push(token);
                token.clear();
            }
    }
        vector<string> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
            reverse(result.begin(),result.end());
            string res = "";
            for(string s:result){
                res += "/"+s;
            }
            if(res.empty()) res = "/";
            return res;
    }
};