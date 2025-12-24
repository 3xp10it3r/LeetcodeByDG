class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, j = 0, n = nums.size();

        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        while(j < n) {
            while(j < n && j - i + 1 <= k) {
                pq.push({nums[j], j});
                j++;
            }

            while(!pq.empty() && pq.top().second < i) pq.pop();
            if(!pq.empty()) ans.push_back(pq.top().first);
            i++;
        }

        return ans;
    }
};