class Solution {
public:
    int largestRectangleAreaInHistogram(vector<int>& heights) {
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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> prefixSum(n, vector<int>(m, 0));

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) {
                if(i == 0) {
                    prefixSum[i][j] = matrix[i][j] - '0';
                    continue;
                }

                if(matrix[i][j] == '0')
                    prefixSum[i][j] = 0;
                else {
                    prefixSum[i][j] =  (matrix[i][j] - '0') + prefixSum[i-1][j];
                }
            }
        }

        for(int i = 0; i < n; i++){
            ans = max(ans, largestRectangleAreaInHistogram(prefixSum[i]));
        }

        return ans;
    }
};