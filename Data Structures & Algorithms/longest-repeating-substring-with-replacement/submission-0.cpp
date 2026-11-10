class Solution {
public:
    int characterReplacement(string s, int k) {

        int n=s.size();
        int l=0,r=0;
        unordered_map<char,int> mp;

        int max_length=0;
        pair<char,int> max_freq={'A',0};
        while(r<n){
            mp[s[r]]++;
            if(mp[s[r]]>max_freq.second){
                max_freq={s[r],mp[s[r]]};
            }
            int subStringLength = r-l+1;
            int maxChanges = subStringLength-max_freq.second;
            if(k>=maxChanges){
                max_length=max(max_length,subStringLength);
            }
            else{
                mp[s[l]]--;
                if(s[l]==max_freq.first){
                    max_freq.second--;
                }
                l++;
            }
            r++;
        }
        return max_length;
    }
};
