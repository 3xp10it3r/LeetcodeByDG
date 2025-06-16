class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        
        vector<int> lastLeftOneIndex(n, -1);
        vector<int> lastRightOneIndex(n, -1);
        
        
        for(int i = 0; i < n; i++) {
            if(seats[i] == 1) {
                lastLeftOneIndex[i] = i;
            } else if(i - 1 >= 0) {
                lastLeftOneIndex[i] = lastLeftOneIndex[i-1];
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (seats[i] == 1) {
                lastRightOneIndex[i] = i;
            } else if (i + 1 < n) {
                lastRightOneIndex[i] = lastRightOneIndex[i + 1];
            }
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(seats[i] == 0) {
                int mn = 0;
                if(lastLeftOneIndex[i] != -1) {
                    mn = i - lastLeftOneIndex[i];
                }
                if(lastRightOneIndex[i] != -1) {
                    mn = (mn != 0 ? min(lastRightOneIndex[i] - i, mn) : lastRightOneIndex[i] - i) ;
                }
                
                ans = max(ans, mn);
            } 
        }
        
        return ans;
    }
};