class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        int maxElementIndex = -1;
        int maxElement = -1e9;
        for(int i = 0; i < n; i++) {
            if(maxElement <= nums[i]) {
                maxElement = nums[i];
                maxElementIndex = i;
            }
        }

        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = maxElementIndex; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else ans[i] = nums[st.top()];
            st.push(i);
        }

        for(int i = n-1; i > maxElementIndex; i--) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else ans[i] = nums[st.top()];
            st.push(i);
        }

        return ans;
    }
};