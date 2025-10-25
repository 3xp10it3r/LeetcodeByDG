class Solution {
public:
    int totalMoney(int n) {
        int terms = n / 7;
        int first = 28; //since 1+2+3+4+5+6+7
        int last = 28 + (terms - 1) * 7; // since for each we are getting 7 more

        int fullWeeksSum = terms * (first + last) / 2;

        int remainingDaysSum = 0;
        int monday = 1 + terms;

        for(int day = 0; day < (n % 7); day++) {
            remainingDaysSum += monday + day;
        }

        return fullWeeksSum + remainingDaysSum;
    }
};