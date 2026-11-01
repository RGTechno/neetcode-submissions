class Solution {
   public:
    int trap(vector<int>& height) {
        int n = height.size();

        int pref[20000] = {0}, suff[20000] = {0};

        for (int i = 1; i < n; i++) {
            pref[i] = max(pref[i - 1], height[i - 1]);
        }

        
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = max(suff[i + 1], height[i + 1]);
        }
        
        int total = 0;
        for (int i = 0; i < n; i++) {
            int calc = (min(pref[i], suff[i]) - height[i]);
            if (calc > 0) {
                total += calc;
            }
        }
        return total;
    }
};
