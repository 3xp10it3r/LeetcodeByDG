class Solution {
public:
    int minOperations(string s) {
        // int n = s.size();
        set<char> st(s.begin(), s.end());
        
        vector<char> v(st.begin(), st.end());

        int n = v.size();

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, (26 - (v[i] - 'a'))  % 26);
        }

        return ans;
    }
};

// xyz
// yyz
// zzz
// aaa