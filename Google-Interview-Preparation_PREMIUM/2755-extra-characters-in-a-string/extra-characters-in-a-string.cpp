class Solution {
public:
    int helper(int level, string& s, unordered_set<string>& mp, vector<int>& dp) {
        if(level >= s.size()) return 0;

        if(dp[level] != -1) return dp[level];

        string curStr = "";

        int ans = s.size();

        for(int i = level; i < s.size(); i++) {
            curStr.push_back(s[i]);

            int count = ((mp.count(curStr)) ? 0: curStr.size()) 
                        + helper(i + 1, s, mp, dp); 
           
            ans = min(ans, count);
        }

        return dp[level] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size(), -1);

        unordered_set<string> mp;

        for(string &word: dictionary) mp.insert(word);

        return helper(0, s, mp, dp);
    }
};