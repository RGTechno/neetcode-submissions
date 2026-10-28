class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            int freq[26] = {0};
            string s = strs[i];
            for (int j = 0; j < s.size(); j++) {
                freq[s[j] - 'a']++;
            }

            string key = "";
            for (int i = 0; i < 26; i++) {
                key.push_back(freq[i]+'0');
            }
           
            if (m.find(key) != m.end()) {
                m[key].push_back(s);
            } else {
                m[key] = {s};
            }
        }
        vector<vector<string>> res;
        for (auto it : m) {
            res.push_back(it.second);
        }
        return res;
    }
};
