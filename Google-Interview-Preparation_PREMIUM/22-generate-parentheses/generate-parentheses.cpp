class Solution {
public:
    string s;
    vector<string> ans;

    void helper(int n, int open, int close) {
        if(open + close  ==  2 * n) {
           
            ans.push_back(s);
            return;
        }

        if(open < n) {

            s += "(";

            helper(n, open + 1, close);

            s.pop_back();
        } 
    
        if(close < open) {
            s += ")";

            helper(n, open, close + 1);

            s.pop_back();
        }
      
    }    
    vector<string> generateParenthesis(int n) {
        s = "";
        helper(n, 0, 0);
        return ans;
    }
};