class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        for (int i = 0; i < position.size(); i++) {
            v.push_back({position[i], i});
        }

        sort(v.begin(), v.end());

        vector<double> time;
        int fleet = position.size();
        for (int i = 0; i < v.size(); i++) {
            double current = double(target - v[i].first) / speed[v[i].second];
        time.push_back(current);
         
        }

        stack<double> st;
        int n=time.size();

        st.push(time[n-1]);

        for(int i=n-2;i>=0;i--){
            if(time[i]>st.top()) st.push(time[i]);
        }

        return st.size();
    }
};
