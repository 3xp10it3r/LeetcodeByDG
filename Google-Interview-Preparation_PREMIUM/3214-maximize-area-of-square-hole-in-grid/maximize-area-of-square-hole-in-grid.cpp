class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int cur = 1, mxH = 1; 
        for(int i = 1; i < hBars.size(); i++) {
            if(hBars[i] - hBars[i-1] == 1) {
                cur++;
            } else cur = 1;
            mxH = max(mxH, cur);
        }

        cur = 1;
        int mxV = 1; 
        for(int i = 1; i < vBars.size(); i++) {
            if(vBars[i] - vBars[i-1] == 1) {
                cur++;
            } else cur = 1;
            mxV = max(mxV, cur);
        }

        int ansSide = min(mxV, mxH) + 1;

        return ansSide * ansSide;
    }
};