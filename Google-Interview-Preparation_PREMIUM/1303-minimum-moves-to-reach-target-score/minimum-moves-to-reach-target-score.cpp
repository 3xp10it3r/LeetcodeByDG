class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cur = target;
        int moves = 0;
        while(cur > 1) {
            if(maxDoubles) {
                if(cur % 2 == 0) {
                    cur /= 2;
                    maxDoubles--;
                } else {
                    cur--;
                }
            } else {
                break;
            }
            moves++;
        }

        return moves + cur - 1;
    }
};