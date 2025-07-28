class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mxOr = 0;

        for(auto num : nums) {
            mxOr |= num;
        }

        int ans = 0;

        int n = nums.size();

        int numberOfSubsets = (1 << n);

        for(int mask = 0; mask < numberOfSubsets; mask++) {
            int curOr = 0;
            for(int i = 0; i < n; i++) {
                if((mask >> i) & 1) {
                    curOr |= nums[i];
                }
            }

            if(curOr == mxOr) {
                ans++;
            }
        } 

        return ans;
    }
};