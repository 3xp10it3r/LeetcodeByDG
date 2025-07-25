class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;

        int ans = 0;
        int maxValNegative = -101;

        for(auto num : nums) {
            if(!st.count(num)){
                st.insert(num);
                if(num > 0) {
                    ans += num;
                } else {
                    maxValNegative = max(maxValNegative, num);
                }
            }
        }

        if(ans == 0 && maxValNegative != -101) return maxValNegative;

        return ans; 
    }
};