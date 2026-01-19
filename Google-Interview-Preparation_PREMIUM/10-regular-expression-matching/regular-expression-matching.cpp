class Solution {
public:
    int n, m;

    bool helper(int i, int j, string& s, string& p) {
        if(j == m) return i == n;

        bool firstMatch = (i < n && (p[j] == '.' || s[i] == p[j]));

        if(j + 1 < m && p[j + 1] == '*') {
            return helper(i, j + 2, s, p) || (firstMatch && helper(i+1, j, s, p));
        } else {
            return firstMatch && helper(i + 1, j + 1, s, p);
        }

    }

    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();

        return helper(0, 0, s, p);
    }
};