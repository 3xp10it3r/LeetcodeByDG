class Solution {
public:
    int removePattern(string &s, string pattern, int score) {
        int ans = 0;

        string st;

        for(auto &ch: s) {
            st.push_back(ch);

            if(st.size() >= 2 && st.substr(st.size() - 2) == pattern) {
                ans += score;
                st.pop_back();
                st.pop_back();
            }
        }

        s = st;
        return ans;
    }

    int maximumGain(string s, int x, int y) {
        int ans = 0;

        if(x >= y) {
            ans += removePattern(s, "ab", x);
            ans += removePattern(s, "ba", y);
        } else {
            ans += removePattern(s, "ba", y);
            ans += removePattern(s, "ab", x);
        }

        return ans;
    }
};