class Solution {
   public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int minele = INT_MAX;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            // check sorted
            if (nums[l] <= nums[mid] && nums[mid] <= nums[r]) {
                minele = min(minele, nums[l]);

                break;
            }

            // left sorted
            if (nums[l] <= nums[mid]) {
                minele = min(minele, nums[l]);
                l = mid + 1;
            } else {
                // right sorted
                minele = min(minele, nums[mid]);
                r = mid - 1;
            }
        }
        return minele;
    }
};
