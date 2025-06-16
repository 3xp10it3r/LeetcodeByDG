class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        
        if(n == 0) {
            return {{lower, upper}};
        }
        
        vector<vector<int>> ans;
        
        if(lower < nums[0]) {
            ans.push_back({lower, nums[0] - 1});
        }
        
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] < lower) {
                continue;
            }
            
            if(nums[i] + 1 != nums[i+1]) {
                int lowerBound = nums[i] + 1;
                int upperBound = nums[i + 1] - 1;
                int flag = 0;
                if(upperBound > upper) {
                    upperBound = upper;
                    flag = 1;
                }
                ans.push_back({lowerBound, upperBound}); 
                if(flag) {
                    return ans;
                }
            }   
        }
        
        if(nums[n-1] < upper) {
            ans.push_back({nums[n-1] + 1, upper});
        }
        
        return ans;
    }
};