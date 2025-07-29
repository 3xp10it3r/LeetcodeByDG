class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 0);
        vector<int> setBitsPos(31, -1);

        for(int i = n - 1; i >= 0; i--) {
            int mx = i;
            for(int bit = 0; bit < 31; bit++) {
                if(nums[i] & (1 << bit)) {
                    setBitsPos[bit] = i;
                } else {
                    mx = max(mx, setBitsPos[bit]);
                }
            }

            ans[i] = mx - i + 1;
        }

        return ans;
    }
};