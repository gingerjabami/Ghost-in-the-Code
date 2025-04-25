class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
         long long ans = 0;
        unordered_map<int, long long> freq;
        freq[0] = 1; 
        int count = 0;

        for (int num : nums) {
            if (num % modulo == k) {
                count++;
            }
            int cur = count % modulo;
            int target = (cur - k + modulo) % modulo;

            if (freq.count(target)) {
                ans += freq[target];
            }

            freq[cur]++;
        }

        return ans;
    }
};