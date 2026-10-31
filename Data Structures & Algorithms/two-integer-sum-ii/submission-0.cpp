class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=1,j=n;
        while(j>i){
            int sum = numbers[i-1]+numbers[j-1];
            if(sum==target){
                return {i,j};
            }
            if(sum>target) j--;
            else i++;
        }
    }
};
