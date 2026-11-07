class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        unordered_set<string> m={"+","-","*","/"};
        for (int i = 0; i < n; i++) {
            if (m.find(tokens[i])==m.end()) {
                // cout << i << "," << tokens[i] << endl;
                int num = stoi(tokens[i]);
                // cout << num << endl;
                st.push(num);
            } else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int c;
                if (tokens[i] == "+") {
                    c = b + a;
                } else if (tokens[i] == "-")
                    c = b - a;
                else if (tokens[i] == "*")
                    c = b * a;
                else
                    c = b / a;
                st.push(c);
            }
        }
        return st.top();
    }
};
