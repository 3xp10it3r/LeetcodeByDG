class Solution {
public:
    const vector<int> dx = {-1, 1, 0, 0};
    const vector<int> dy = {0, 0, -1, 1};

    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int,int>> q;

        int freshCount = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2){
                    q.push({i, j});
                    visited[i][j] = 1;
                }
                else if(grid[i][j] == 1) freshCount++;
            }
        }

        int minutes = 0;

        while(!q.empty()) {
            int sz = q.size();

            bool anyRotten = false;
            for(int i_ = 0; i_ < sz; i_++) {
                pair<int,int> node = q.front(); 
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int ni = node.first + dx[i];
                    int nj = node.second + dy[i];

                    if(isValid(ni, nj, n, m) && grid[ni][nj] == 1 && !visited[ni][nj]) {
                        visited[ni][nj] = 1;
                        q.push({ni, nj});
                        anyRotten = true;
                        freshCount--;
                    }
                }
            }
            if(anyRotten)
                minutes++;
        }

        if(freshCount == 0) return minutes;
        return -1;
    }
};