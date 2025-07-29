class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n, 0);
        vector<int> setBitsPos(31, -1);

        for(int i = n - 1; i >= 0; i--) {
            int mx = i;
            for(int j = 0; j < 31; j++) {
                if(nums[i] & (1 << j)) {
                    setBitsPos[j] = i;
                } else {
                    mx = max(mx, setBitsPos[j]);
                }
            }

            ans[i] = mx - i + 1;
        }

        return ans;
    }
};