class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<pair<int, int>> left_small, right_small;
        vector<int> left(n, -1);
        vector<int> right(n, n);

        // right
        for (int i = 0; i < n; i++) {
            while (!right_small.empty() && heights[i] < right_small.top().first) {
                right[right_small.top().second] = i;
                right_small.pop();
            }
            right_small.push({heights[i], i});
        }

        // left
        for (int i = n - 1; i >= 0; i--) {
            while (!left_small.empty() && heights[i] < left_small.top().first) {
                left[left_small.top().second] = i;
                left_small.pop();
            }
            left_small.push({heights[i], i});
        }

        int max_area = 0;

        for (int i = 0; i < n; i++) {
            int current_height_area = heights[i] * ((right[i] - 1) - (left[i] + 1) + 1);
            max_area = max(max_area, current_height_area);
        }
        return max_area;
    }
};
