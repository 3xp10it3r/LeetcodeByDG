class Solution {
public:

    bool checkSame(int f1[], int f2[]) {
        for(int i = 0; i < 26; i++) {
            if(f1[i] != f2[i]) return false;
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if(n > m) return false;

        int freq[26] = {0};

        for(auto& ch: s1) {
            freq[ch - 'a']++;
        }

        int windowFreq[26] = {0};

        int i = 0;

        for(; i < n; i++) {
            windowFreq[s2[i]-'a']++;
            if(checkSame(freq, windowFreq)) return true;
        }

        int j = 0;

        while(i < m) {
            windowFreq[s2[j] - 'a']--;
            windowFreq[s2[i] - 'a']++;
            if(checkSame(freq, windowFreq)) return true;
            i++;
            j++;
        }

        return false;
    }
};

// a = 1;
// b = 1;

