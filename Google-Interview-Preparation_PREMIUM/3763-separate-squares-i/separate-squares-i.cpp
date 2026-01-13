class Solution {
public:
    const double EPS = 1e-5;
    double totalArea = 0;

    bool check(double Y, vector<vector<int>>& squares) {
        double area = 0;

        for(auto &square: squares) {
            double x = (double) square[0];
            double y = (double) square[1];
            double l = (double) square[2];

            if(y + l <= Y) {
                area += l * l;
            }
            else if(y < Y) {
                area += (Y - y) * l;
            }
        }

        return area * 2 >= totalArea;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double lo = 0;
        double hi = 1e9;
        double mxY = 0;
        for(auto& square: squares) {
            totalArea += (double)square[2] * square[2];
            mxY = max(mxY, (double)square[1] + square[2]); // y + l
        }

        hi = mxY;

        double ans = 0;

        while(abs(hi - lo) >= EPS) {
            double mid = lo + (hi - lo) / 2;

            if(check(mid, squares)) {
                ans = mid;
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return ans;
    }
};