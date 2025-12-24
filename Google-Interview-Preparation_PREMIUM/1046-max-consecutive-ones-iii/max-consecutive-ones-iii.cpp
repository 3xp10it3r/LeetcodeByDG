class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        // ds
        int cntZero = 0;
        int ans = 0;

        int head = -1, tail = 0;

        while(tail < n) {
            while(head + 1 < n && (nums[head + 1] == 1 || cntZero < k)) {
                head++;
                if(nums[head] == 0) cntZero++;
            }

            ans = max(ans, head - tail + 1);

            if(tail > head) {
                tail++;
                head = tail - 1;
            } else {
                if(nums[tail] == 0) cntZero--;
                tail++;
            }
        }

        return ans;
    }
};