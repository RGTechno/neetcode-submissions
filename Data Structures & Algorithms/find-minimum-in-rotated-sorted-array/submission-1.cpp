class Solution {
public:
    int findMin(vector<int> &nums) {

        int l=0,r=nums.size()-1;
        int minele = INT_MAX;

        while(l<=r){
            int mid = l+(r-l)/2;
            minele = min(minele,nums[mid]);

            // check sorted
            if(nums[l]<nums[mid] && nums[mid]<nums[r]){
                r--;
                continue;
            }


            // left unsorted
            if(nums[l]>nums[mid]){
                r=mid-1;
            }
            else{
                // right unsorted
                l=mid+1;
            }
        }
        return minele;
        
    }
};
