class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int seg = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '0') continue;
            if(s[i] == '1') {
                if(i-1 >= 0 && s[i-1] == '1') continue;
                else seg++;
            }
        }

        return seg <= 1;
    }
};