class Solution {
public:
    bool checkPalindrome(int i, int j, string& s) {
        while(i <= j) {
            if(s[i] == s[j]) i++, j--;
            else return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        string ans = ""; int len = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(checkPalindrome(i, j, s)) {
                    if(len < j - i + 1) {
                        ans = s.substr(i, j - i + 1);
                        len = j - i + 1;
                    }
                }
            }
        }

        return ans;
    }
};