class Solution {
   public:
    string encode(vector<string>& strs) {
        string s = "";
        for (int i = 0; i < strs.size(); i++) {
            s.append(to_string(strs[i].size()));
            s.push_back('|');
            s.append(strs[i]);
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> decodedStrings;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                if (s[j] == '|') {
                    int num = stoi(s.substr(i, j - i));
                    string decodedString = s.substr(j+1,num);
                    decodedStrings.push_back(decodedString);
                    i = j + num;
                    break;
                }
            }
        }
        return decodedStrings;
    }
};
