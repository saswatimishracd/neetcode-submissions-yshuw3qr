class Solution {
public:

    string repeatString(string s, int k){
        string res="";
        for(int i=0;i<k;i++){
            res += s;
        }
        return res;
    }

    string decodeString(string s) {
        string curString = "";
        int curNum = 0;
        stack<string> stringStack;
        stack<int> numberStack;
        for(char ch:s){
            if(ch=='['){
                stringStack.push(curString);
                numberStack.push(curNum);
                curNum=0; curString="";
            }
            else if(ch == ']'){
                int repeat = numberStack.top();
                curString = stringStack.top() + repeatString(curString,repeat);
                stringStack.pop();
                numberStack.pop();
            }
            else if(isdigit(ch)){
                curNum = curNum*10 + ch-'0';
            }
            else{
                curString += ch;
            }
        }
        return curString;
    }
};