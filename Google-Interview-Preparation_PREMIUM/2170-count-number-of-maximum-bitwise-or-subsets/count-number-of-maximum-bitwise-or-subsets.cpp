class Solution {
public:
    int ans;

    void helper(int level, vector<int>& nums, int curOr, int n, int mxOr) {
        if(level == n) {
            if(curOr == mxOr) ans++;
            return;
        }

        helper(level + 1, nums, curOr | nums[level], n, mxOr);
        helper(level + 1, nums, curOr, n, mxOr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int mxOr = 0;

        for(auto num : nums) {
            mxOr |= num;
        }

        ans = 0;
        
        helper(0, nums, 0, n, mxOr);

        return ans;
    }
};