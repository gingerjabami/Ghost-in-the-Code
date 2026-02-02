class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxm= nums[0];
        int sum =nums[0];
        for (int i = 1  ; i< nums.size(); i++ ){
            
            //for(int j =i; j <nums.size(); j++){
                sum = max(nums[i],sum + nums[i]);
                maxm = max(maxm, sum);
                //if(sum < 0)
                //sum = 0;
           //}
        }
        return maxm;
    }
};