class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // bruteforce - 2loops;

        // better - (n log n) with sorting

        // optimal - O(n) using hashmap

        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) {
            if(mp.find(target - nums[i]) != mp.end()) {
                return {mp[target - nums[i]], i};
            }

            mp[nums[i]] = i;
        }

        return {-1, -1};
    }
};