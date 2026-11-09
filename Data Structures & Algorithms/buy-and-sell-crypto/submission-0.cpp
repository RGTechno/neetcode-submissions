class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
int max_profit=0;
        int l=0;
        while(l<n-1){
            int r=l+1;
            while(r<n){
                max_profit=max(max_profit,(prices[r]-prices[l]));
                r++;
            }
            l++;
        }
        return max_profit;
    }
};
