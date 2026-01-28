class Solution {
public:
static bool chan(const pair<int, pair<int,int>>& a,
                 const pair<int, pair<int,int>>& b){
    if(a.first!=b.first){
        return a.first > b.first;
  }
  if(a.second.first != b.second.first){
    return a.second.first < b.second.first;
  }
  return a.second.second < b.second.second;
}

    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int n = towers.size();
        int cx= center[0];
        int cy= center[1];
        vector<pair<int, pair<int,int>>> v;
        for(int i=0; i<n ; i++){
            int x= towers[i][0];
            int y= towers[i][1];
            int q= towers[i][2];

            int d = abs(cx - x) + abs(cy - y);
            if(d<= radius){
                v.push_back({q,{x,y}});
            }
        }
if(v.empty()){
    return{-1,-1};
}
        sort(v.begin(), v.end(), chan);

        return {v[0].second.first, v[0].second.second};
    }
};