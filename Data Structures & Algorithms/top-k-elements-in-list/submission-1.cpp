class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        int maxFreq=0;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
            maxFreq = max(maxFreq,count[nums[i]]);
        }

        vector<int> result;

        for(int i=maxFreq;i>=1;i--){
            for(auto c:count){
                if(c.second==i){
                    result.push_back(c.first);
                }
                if(result.size()==k) return result;
            }
        }
    }
};
