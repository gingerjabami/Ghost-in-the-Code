class Solution {
public:
   int count(int val, vector<int>& top, vector<int>& bottom) {
        int toTop = 0, toBottom = 0;

        for (int i = 0; i < top.size(); ++i) {
            if (top[i] != val && bottom[i] != val) return -1;
            else if (top[i] != val) toTop++;
            else if (bottom[i] != val) toBottom++;
        }

        return min(toTop, toBottom);
    }

    int minDominoRotations(vector<int>& top, vector<int>& bottom) {
        int res = count(top[0], top, bottom);
        if (res != -1 || top[0] == bottom[0]) return res;
        return count(bottom[0], top, bottom);
    }
};