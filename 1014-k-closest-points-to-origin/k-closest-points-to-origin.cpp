class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>> pq;

        int n = points.size();

        for(int i = 0; i < n; i++) {
            if(pq.size() > k) {
                pq.pop();
            }

            int dist = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            pq.push({dist, points[i]});
        }

        if(pq.size() > k) {
                pq.pop();
        }

        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};