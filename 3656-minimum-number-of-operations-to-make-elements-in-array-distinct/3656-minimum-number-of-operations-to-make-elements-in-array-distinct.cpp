class Solution {
public:
    int minimumOperations(vector<int>& nums) {
         int n = nums.size();
        for (int i = 0; i <= (n + 2) / 3; ++i) {
            int start = 3 * i;
            if (start >= n) return i; 
            unordered_set<int> view;
            bool chec = true;
            for (int j = start; j < n; ++j) {
                if (view.count(nums[j])) {
                    chec = false;
                    break;
                }
                view.insert(nums[j]);
            }
            if (chec) return i;
        }
        return (n + 2) / 3; 
    }
};