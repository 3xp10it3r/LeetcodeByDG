class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mp;
        for(auto num : nums) {
            mp[(num % value + value) % value]++;
        }

        for(int i = 0; i <= 1e5; i++) {
            if(!mp[i % value])
                return i;
            else mp[i % value]--;
        }


        // int ans = 0;

        return -1;
    }
};