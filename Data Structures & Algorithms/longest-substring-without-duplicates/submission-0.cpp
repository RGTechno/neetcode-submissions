class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n=s.size();
        unordered_set<char> st;

        int l=0,r=0;
        int max_length=0;
        while(r<n){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                r++;
                int x=st.size();
                max_length=max(max_length,x);
            }else{
                st.erase(s[l]);
                l++;
            }
        }
        return max_length;
    }
};
