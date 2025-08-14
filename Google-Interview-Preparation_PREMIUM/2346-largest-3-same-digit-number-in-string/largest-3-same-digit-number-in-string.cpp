class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        char mxDigit = '\0';
        for(int i = 0; i <= n - 3; i++) {
            if(num[i] == num[i+1] && num[i+1] == num[i+2]) {
                mxDigit = max(mxDigit, num[i]);
            }
        }

        return mxDigit == '\0' ? "" : string(3, mxDigit);
    }
};