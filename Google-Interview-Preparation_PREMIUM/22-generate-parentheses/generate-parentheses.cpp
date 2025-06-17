class Solution {
public:
    string s;
    vector<string> ans;

    bool isBalanced(string& s) {
        int cnt = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') cnt++;
            else {
                if(cnt <= 0) return false;
                cnt--;
            }
        }

        return cnt == 0;
    }

    void helper(int n) {
        if(n == 0) {
            if(isBalanced(s)) {
                ans.push_back(s);
            }
            return;
        }

        s += "(";

        helper( n - 1 );

        s.pop_back();

        s += ")";

        helper(n-1);

        s.pop_back();
    }    
    vector<string> generateParenthesis(int n) {
        s = "";
        helper(2 * n);
        return ans;
    }
};