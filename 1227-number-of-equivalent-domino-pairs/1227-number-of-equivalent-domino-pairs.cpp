class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
          map<pair<int, int>, int> count;
        int res = 0;
        
        for (const auto& domino : dominoes) {
            int a = domino[0];
            int b = domino[1];
            pair<int, int> key = {min(a, b), max(a, b)};
            count[key]++;
        }
        
        for (const auto& entry : count) {
            int n = entry.second;
            res += n * (n - 1) / 2;
        }
        
        return res;
    }
};