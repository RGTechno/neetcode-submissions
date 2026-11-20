class Solution {
public:
int hoursRequired(vector<int> &piles,int rate){
    int hours=0;
    for(auto i:piles){
        hours = hours+(i+rate-1)/rate;
    }
    return hours;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=INT_MAX;
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            int hr=hoursRequired(piles,mid);
            if(hr<=h){
                r=mid-1;
                ans=min(ans,mid);
            }else l=mid+1;
        }
        return ans;
    }
};
