class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0) return false;
        map<char,char> mapper = {{'(',')'},{'{','}'},{'[',']'}};
        stack<char> st;
        for(auto i:s){
            if(i=='('||i=='{'||i=='['){
                st.push(i);
            }
            else{
                if(st.empty()) return false;
                if(mapper[st.top()]==i){
                    st.pop();
                }else return false;
            }
        }

        return !st.size();
    }
};
