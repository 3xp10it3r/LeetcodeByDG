class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int ans = 0;

        for(auto ch: s) {
            mp[ch]++;
        }

        bool flag = 0;

        for(auto &[ch, count] : mp) {
            if(count % 2 == 0) ans += count;
            else{
                ans += (count - 1);
                flag = 1;
            }
        }

        if(flag) return ++ans;
        return ans;
    }
};