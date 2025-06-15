class Solution {
public:

    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        vector<vector<int>> dist(n, vector<int>(m, 1e8));

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()) {
            auto node = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int newI = node.first + dx[k];
                int newJ = node.second + dy[k];

                if(isValid(newI, newJ, n, m) && !vis[newI][newJ]) {
                    if(dist[newI][newJ] > dist[node.first][node.second] + 1) {
                        q.push({newI, newJ});
                        vis[newI][newJ] = 1;
                        dist[newI][newJ] = dist[node.first][node.second] + 1;
                    }
                }
            }
        }


        return dist;
    }
};

// m * n * (m * n + m * n) - TLE
