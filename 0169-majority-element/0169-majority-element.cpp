class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> m;
        for(int i: nums){
            m[i]++;
        }
       int ans= -1;
       int freq=0;
       for(auto &x : m){
        if(x.second > freq){
            freq = x.second;
            ans=x.first;
        }
       }
       return ans;
       // return *m.rbegin();
    }
};