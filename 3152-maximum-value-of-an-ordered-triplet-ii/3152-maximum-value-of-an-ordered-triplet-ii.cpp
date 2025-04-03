class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
     int n = nums.size();
        if (n < 3) return 0; 
        
        long long diff = LLONG_MIN;
        long long ans = 0;
        int prev = nums[0];

    
        for (int j = 1; j < n - 1; j++) {
            diff = max(diff, (long long)prev - nums[j]); 
            prev = max(prev, nums[j]);
            
            ans = max(ans, diff * nums[j + 1]); 
        }
        
        return ans;
    }
};