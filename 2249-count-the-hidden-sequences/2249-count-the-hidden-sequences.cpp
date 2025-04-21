class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
         long minp = 0, maxp = 0, sum = 0;
        
        for (int diff : differences) {
            sum += diff;
            minp = min(minp, sum);
            maxp = max(maxp, sum);
        }

        long minstart = lower - minp;
        long maxstart = upper - maxp;

        return max(0L, maxstart - minstart + 1);
    }
};