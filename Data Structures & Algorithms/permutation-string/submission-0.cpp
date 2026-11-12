class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        unordered_map<char, int> mp1;
        for (int i = 0; i < n1; i++) {
            mp1[s1[i]]++;
        }

        int l = 0, r = n1 - 1;

        while (r < n2) {
            int i = l;
            unordered_map<char, int> mp2;
            while (i <= r) {
                if (mp1.find(s2[i]) == mp1.end()) {
                    // not found -- not a valid substring;
                    break;
                }
                mp2[s2[i]]++;
                if (mp1[s2[i]] < mp2[s2[i]]) {
                    // freq of char exceeds -- not a valid substring
                    break;
                }
                i++;
            }
            if (i == r + 1) return true;
            l++;
            r++;
        }
        return false;
    }
};
