class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int i = 0, j = n - 1;
        long mw = 0;
        while (j > i) {
            long area = (j-i)*min(heights[i],heights[j]);
            mw=max(mw,area);
            if(heights[i]<heights[j]) i++;
            else j--;
        }
        return mw;
    }
};
