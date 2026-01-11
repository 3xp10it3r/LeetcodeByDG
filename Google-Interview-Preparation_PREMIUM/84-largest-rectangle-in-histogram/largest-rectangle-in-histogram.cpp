class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;

        int maxArea = 0;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int idx = st.top(); st.pop();

                int nextSmallerElementIndex = i;
                int previousSmallerElementIndex = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, heights[idx] * (nextSmallerElementIndex - previousSmallerElementIndex - 1));
            }
            st.push(i);
        }

        while(!st.empty()) {
            int idx = st.top(); st.pop();

            int nextSmallerElementIndex = n;
            int previousSmallerElementIndex = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, heights[idx] * (nextSmallerElementIndex - previousSmallerElementIndex - 1));
        }

        return maxArea;
    }
};