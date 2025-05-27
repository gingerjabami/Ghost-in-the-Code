class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total = n * (n + 1) / 2;
        int k = n / m;
        int sum = m * k * (k + 1) / 2;
        int notsum = total - sum;
        return notsum - sum;
    }
};