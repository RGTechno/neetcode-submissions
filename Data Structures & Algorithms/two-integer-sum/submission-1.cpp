class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int ele = target-nums[i];
            auto it=m.find(ele);
            if(it!=m.end()) {
                int j=it->second;
                if(i<j) return {i,j};
                return {j,i};
            };
            m[nums[i]]=i;
        }
    }
};
