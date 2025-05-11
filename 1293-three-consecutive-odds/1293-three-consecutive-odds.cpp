class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
         int c = 0;
        for (int num : arr) {
            if (num % 2 == 1) {
                c++;
                if (c == 3) return true;
            } else {
                c = 0;
        }
            }    
            return false;
    }


};