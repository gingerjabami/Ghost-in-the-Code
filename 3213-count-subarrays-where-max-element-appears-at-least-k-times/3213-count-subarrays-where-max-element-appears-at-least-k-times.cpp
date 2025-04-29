class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
         int maxelem = *max_element(nums.begin(), nums.end());
        long long res = 0;
        int left = 0, count = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == maxelem) {
                ++count;
            }

            while (count >= k) {
                if (nums[left] == maxelem) {
                    --count;
                }
                ++left;
            }
            res += left;
        }

        return res;
    }
};