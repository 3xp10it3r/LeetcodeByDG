class Solution {
private:
    static int getDistance(vector<int>& v) {
        return v[0] * v[0] + v[1] * v[1];
    }
public:
    

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return getDistance(a) < getDistance(b);
        });

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};