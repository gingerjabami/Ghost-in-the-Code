class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
          int n = nums.size();
        long long ans = 0;

        for (int j = 1; j < n - 1; ++j) {
            int max_i = 0;  
            for (int i = 0; i < j; ++i) {
                max_i = max(max_i, nums[i]);
            }

            int max_k = 0;  
            for (int k = j + 1; k < n; ++k) {
                max_k = max(max_k, nums[k]);
            }

            long long triplet_value = (1LL * (max_i - nums[j]) * max_k);
            ans = max(ans, triplet_value);
        }

        return ans;
    }
};