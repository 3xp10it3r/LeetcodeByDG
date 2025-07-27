class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<int> countL(n, 0), countT(n, 0);

        for(int i = 0; i < n; i++) {
            if(i) countL[i] += countL[i-1];
            countL[i] += (s[i] == 'L');
        }

        for(int i = n - 1; i >= 0; i--) {
            if(i + 1 < n) countT[i] += countT[i + 1];
            countT[i] += (s[i] == 'T');
        }

        long long ans = 0;
        long long ansWithT = 0;
        long long ansWithL = 0;

        long long maxLT = 0;

        for(int i = 0; i < n; i++) {
            int prefixL = (i-1 >= 0) ? countL[i-1] : 0;
            int suffixT = (i+1 < n) ? countT[i+1] : 0;

            if(s[i] == 'C') {
                ans += prefixL * suffixT;
                ansWithL += (prefixL + 1) * suffixT;
                ansWithT += prefixL * (suffixT + 1);
            }

            maxLT = max(1LL * countL[i] * suffixT, maxLT);
        }

        return max({ans + maxLT, ansWithL, ansWithT, ans});
    }
};