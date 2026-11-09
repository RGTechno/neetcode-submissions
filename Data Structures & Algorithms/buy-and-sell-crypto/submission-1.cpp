class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<int> suff(n,-1);

        for(int i=n-2;i>=0;i--){
            suff[i]=max(suff[i+1],prices[i+1]);
        }
        int max_profit=0;
        for(int i=0;i<n;i++){
            max_profit=max(max_profit,(suff[i]-prices[i]));
        }
        return max_profit;
    }
};
