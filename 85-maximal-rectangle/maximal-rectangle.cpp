class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> left(m), right(m, m), height(m);
        
        int mxArea = 0;

        for(int i = 0; i < n; i++) {

            int curLeft = 0, curRight = m;

            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    left[j] = max(left[j], curLeft);
                } else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }

            for(int j = m-1; j >= 0; j--) {
                if(matrix[i][j] == '1') {
                    right[j] = min(right[j], curRight);
                } else {
                    right[j] = m;
                    curRight = j;
                }
            }

            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }

            for(int j = 0; j < m; j++) {
                mxArea = max(mxArea, height[j] * (right[j] - left[j]));
            }
        }

        return mxArea;
    }
};