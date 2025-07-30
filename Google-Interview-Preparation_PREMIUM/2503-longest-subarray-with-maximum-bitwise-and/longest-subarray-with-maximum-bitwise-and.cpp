class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mxNum = *max_element(nums.begin(), nums.end());

        int n = nums.size();
        int cur = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == mxNum) {
                cur++;
            } else {
                cur = 0;
            }

            ans = max(ans, cur);
        }

        return ans;
    }
};