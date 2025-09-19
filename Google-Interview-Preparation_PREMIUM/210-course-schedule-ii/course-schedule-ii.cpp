class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> graph(numCourses);
        vector<int> indeg(numCourses, 0);

        for(int i = 0; i < n; i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indeg[prerequisites[i][1]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indeg[i] == 0) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()) {
            int node = q.front(); q.pop();

            ans.push_back(node);

            
            for(auto neighbour: graph[node]) {
                indeg[neighbour]--;
                if(indeg[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        reverse(ans.begin(), ans.end());

        if(ans.size() == numCourses) return ans;
        return {};
    }
};