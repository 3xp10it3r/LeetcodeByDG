class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;

        stack<int> st;
        st.push(-1);

        int i = 0;

        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && st.top() != -1 && heights[st.top()] >= heights[i]){
                int curHeight = heights[st.top()];
                st.pop();
                
                maxArea = max(maxArea, curHeight* (i - st.top() - 1));
            }

            st.push(i);
        }

        while(st.top() != -1) {
            int curHeight = heights[st.top()]; st.pop();

            int width = heights.size() - st.top() - 1;

            maxArea = max(maxArea, curHeight * width);
        }

        return maxArea;
    }
};