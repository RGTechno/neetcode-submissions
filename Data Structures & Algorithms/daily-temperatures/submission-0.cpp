class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);

        stack<pair<int, int>> st;

        for (int i = 0; i < n; i++) {
            int weather = temperatures[i];
            while (!st.empty() && weather > st.top().first) {
                pair<int, int> topWeather = st.top();
                res[topWeather.second] = (i - topWeather.second);
                st.pop();
            }
            st.push({weather, i});
        }

        return res;
    }
};
