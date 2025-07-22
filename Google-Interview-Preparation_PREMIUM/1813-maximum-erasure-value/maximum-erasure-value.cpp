class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // sliding window of unique element 

        int head = -1, tail = 0;

        // ds

        unordered_map<int, int> mp;

        int sum = 0;
        
        int n = nums.size();

        int ans = 0;

        while(head < n) {
            while(head + 1 < n && mp.count(nums[head + 1]) == 0) {
                head++;

                mp[nums[head]]++;

                sum += nums[head];
            }

            ans = max(ans, sum);

            if(tail > head) {
                head = tail;
                tail++;
            } else {
                mp[nums[tail]]--;
                if (mp[nums[tail]] == 0) mp.erase(nums[tail]);  
                sum -= nums[tail];
                tail++;
            }
        }

        return ans;
    }
};