class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 0 1 1
        vector<vector<int>> res;
        unordered_set<string> st;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        while (n > i) {
            int j = i + 1, k = n-1;
            while (k > j) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    string grouping = "";
                    grouping += (nums[i] + '0');
                    grouping += (nums[j] + '0');
                    grouping += (nums[k] + '0');
                    if (st.find(grouping) == st.end()) {
                        res.push_back({nums[i], nums[j], nums[k]});
                        st.insert(grouping);
                    }
                    k--;
                } else if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                }
            }
            i++;
        }
        return res;
    }
};
