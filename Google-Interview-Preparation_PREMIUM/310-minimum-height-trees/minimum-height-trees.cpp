class Solution {
public:
    // only possible two or onen nodes as answer;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) {
            return {0};
        }

        vector<int> indeg(n, 0);
        vector<vector<int>> graph(n);

        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);

            indeg[u]++;
            indeg[v]++;
        }

        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            if(indeg[i] == 1) {
                q.push(i);
            }
        }

        int remaining = n;

        while(remaining > 2) {
            int sz = q.size();
            remaining -= sz;

            while(sz--) {
                
                auto node = q.front(); q.pop();
                for(auto nei : graph[node]) {
                    indeg[nei]--;
                    if(indeg[nei] == 1) {
                        q.push(nei);
                    }
                }
            }
        }

        vector<int> ans;

        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};