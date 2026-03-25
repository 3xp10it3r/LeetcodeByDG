class Solution {
public:
    int visited[51];
    unordered_map<int, vector<int>> graph;

    void dfs(int i, vector<int>& comp) {
        visited[i] = 1;
        comp.push_back(i);

        for(auto neighbour : graph[i]) {
            if(!visited[neighbour]) {
                dfs(neighbour, comp);
            }
        }
    }


    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // memset(visited, 0, sizeof(visited));
        int ans = 0;
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                vector<int> comp;

                dfs(i, comp);
                int countEdge = 0;
                for(auto node : comp) {
                    countEdge += graph[node].size();
                }

                int componentSize = comp.size();

                if(countEdge == (componentSize * (componentSize - 1))) {
                    ans++;
                }
            }
        }

        return ans;
    }
};