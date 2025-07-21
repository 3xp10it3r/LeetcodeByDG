class Solution {
public:
    string makeFancyString(string s) {
        pair<int, char> last;
        last = {0, s[0]};
        string ans = "";

        ans+=s[0];

        for(int i = 1; i < s.size(); i++) {
            if(s[i] == last.second) {
                if(i - last.first + 1 >= 3) continue;
            } else {
                last = {i, s[i]};
            }
            ans += s[i];
        }

        return ans;
    }
};