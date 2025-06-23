class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxIndex = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] + i > maxIndex) maxIndex = nums[i] + i;
            if(maxIndex == i && i != n-1) return false;
        }

        return true;
    }
};