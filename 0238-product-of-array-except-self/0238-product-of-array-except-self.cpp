class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int n= nums.size();
        vector<int> ans(n,1);
        //int prefix =1;
      //  int suffix = 1; 
      //using prefix and suffix will take a lot of space. loop it thru
   
        int temp=1;
    for(int i = 0; i<n; i++){
        ans[i]=ans[i]*temp;
        temp = temp * nums[i];
    }
    temp=1;
    for(int i = n-1; i>= 0;i--){
        ans[i]= ans[i] * temp;
        temp = temp * nums[i];
    }
return ans;
    }
};