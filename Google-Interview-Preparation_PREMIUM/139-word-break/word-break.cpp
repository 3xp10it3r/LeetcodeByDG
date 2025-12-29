class Solution {
public:
    vector<int> dp;
    int n;

    bool solve(int index, string& s, vector<string>& wordDict) {
        if(index >= n) return 1;

        if(dp[index] != -1) return dp[index];

        for(string& word: wordDict) {
            int len = word.size();
            if(index + len - 1 >= n) continue;

            if(s.substr(index, len) == word && solve(index + len, s, wordDict)) {
                return dp[index] = 1;
            } 
        }

        return dp[index] = 0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        dp = vector(n, -1);

        return solve(0, s, wordDict);
    }
};