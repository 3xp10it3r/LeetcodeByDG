class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        
        int zeroCount = 0, ans = 0;

        for(int i = 0; i < n; i++) {
            if(seats[i] == 1) {
                zeroCount = 0;
            } else {
                zeroCount++;
                ans = max(ans, (zeroCount + 1) / 2); // 1 000 1  (3 + 1)/ 2 = 2
            }
        }

        for(int i = 0; i < n; i++) { // left 0's with no left boundary
            if(seats[i] == 1) {
                ans = max(ans, i);
                break;
            }
        }

        for(int i = n-1; i >= 0; i--) { // right 0's with no right boundary
            if(seats[i] == 1) {
                ans = max(ans, n - i - 1);
                break;
            }
        }

        return ans;
    }
};