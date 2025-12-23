class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // use unordered_set and if there's no value less than that then increase and account for max ans.

        int n = nums.size();
        int ans = 0;

        unordered_set<int> ust(nums.begin(), nums.end());

        for(auto it = ust.begin(); it != ust.end(); it++) {
            if(ust.find(*it - 1) == ust.end()) {
                int curr = 1;
                int start = *it;
                while(ust.find(start + 1) != ust.end()) {
                    curr++;
                    start++;
                }

                ans = max(ans, curr);
            }
        }

        return ans;
    }
};