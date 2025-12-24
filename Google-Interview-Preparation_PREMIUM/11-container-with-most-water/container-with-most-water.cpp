class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i = 0, j = n - 1;

        int mxArea = 0;

        while(i < j) {
            int area = (j - i) * min(height[i], height[j]);
            mxArea = max(mxArea, area);

            if(height[i] < height[j]) i++;
            else j--;
        }

        return mxArea;
    }
};