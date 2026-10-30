class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        set<int> st;

        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        vector<int> v(st.begin(), st.end());

        int maxL = 1, continuos = 1;
        for (int i = 0; i < v.size() - 1; i++) {
            cout<<v[i]<<",";
            if (v[i + 1] - 1 == v[i])
                continuos++;
            else {
                maxL = max(maxL, continuos);
                continuos = 1;
            }
        }
        return max(maxL, continuos);
    }
};
