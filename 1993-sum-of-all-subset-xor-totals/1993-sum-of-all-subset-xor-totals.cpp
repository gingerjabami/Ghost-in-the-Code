class Solution {
public:
   int dfs(vector<int>& nums, int index, int currXor) {
        if (index == nums.size()) {
            return currXor;
        }
        int w = dfs(nums, index + 1, currXor ^ nums[index]);    
        int wo = dfs(nums, index + 1, currXor);
        return w + wo;
    }

    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};