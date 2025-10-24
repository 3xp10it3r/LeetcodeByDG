class Solution {
public:
    int nextBeautifulNumber(int n) {
        int MAX = 1e7;


        for(int i = n + 1; i < MAX; i++) {
            int freq[10] = {0};
            int x = i;
            while(x != 0) {
                freq[x%10]++;
                x /= 10;
            }
            bool flag = true;
            for(int j = 0; j < 10; j++) {
                if(freq[j] > 0 && freq[j] != j) {
                    flag = false;
                    break;
                }
            }
            // cout << i << " " << flag << endl;
            if(flag) return i;
        }

        return -1;
    }
};