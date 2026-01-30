class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int n = towers.size();
        int cx= center[0];
        int cy= center[1];
        int bestquality =0;
        int x= 0;
        int y= 0;
        int q= 0;
       vector<int> result = {INT_MAX, INT_MAX};
        for(int i=0; i<n ; i++){
             x= towers[i][0];
             y= towers[i][1];
             q= towers[i][2];

            int d = abs(cx - x) + abs(cy - y);
            if(d<= radius){
            if ( q > bestquality ){
                bestquality =q;
                result = {x,y};
            }
            else if( q == bestquality){
                result = min(result, {x,y});
            } 
            }
        }
if(result[0] == INT_MAX) return {-1, -1};

return result;


    }
};