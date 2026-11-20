class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) return mid;
            int k = target;
            // left sorted
            if (nums[l] <= nums[mid]) {
                if (nums[l]<=k && k<=nums[mid]) {
                    // in left part
                    r=mid-1;
                } else {
                    l=mid+1;
                }
            }
            else{
                //right sorted
                if(nums[mid]<=k && k<=nums[r]){
                    // in right part
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};
