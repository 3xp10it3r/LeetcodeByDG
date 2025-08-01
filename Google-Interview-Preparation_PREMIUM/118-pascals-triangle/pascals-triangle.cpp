class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;

        v.push_back({1});

        for(int i = 1; i < numRows; i++) {
            vector<int> temp(i+1, 0);
            temp[0]=1;
            for(int j = 1; j < i; j++) {
                temp[j] = v[i - 1][j-1] + v[i-1][j];
            }
            temp[i] = 1;

            v.push_back(temp);
        }

        return v;
    }
};