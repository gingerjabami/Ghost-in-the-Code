class Solution {
public:
    int countGoodNumbers(long long n) {
         const int MOD = 1e9 + 7;

        auto modPow = [](long long base, long long exp, int mod) -> long long {
            long long res = 1;
            while (exp > 0) {
                if (exp % 2) res = res * base % mod;
                base = base * base % mod;
                exp /= 2;
            }
            return res;
        };

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        return modPow(5, even, MOD) * modPow(4, odd, MOD) % MOD;
    }
};