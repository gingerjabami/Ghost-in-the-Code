class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
         int n = nums.size();
        unordered_set<int> d;
        for (int num : nums) {
            d.insert(num);
        }
        int total = d.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            unordered_map<int, int> freq;
            int current = 0;
            for (int j = i; j < n; ++j) {
                if (freq[nums[j]] == 0) {
                    current++;
                }
                freq[nums[j]]++;
                if (current == total) {
                    count++;
                }
            }
        }

        return count;
    }
};