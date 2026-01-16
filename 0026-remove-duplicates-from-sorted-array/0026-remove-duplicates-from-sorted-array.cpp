class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
// this will NOT work using hashmaps and sets
if( nums.empty()){
    return 0;
}
 int ans=1;
 for(int j=1; j<nums.size(); j++){
    if(nums[j]!=nums[ans-1]){
        nums[ans]=nums[j];
        ans++;

    }
 }
return ans;
    }
};