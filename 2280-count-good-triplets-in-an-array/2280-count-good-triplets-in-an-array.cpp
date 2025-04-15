#include <vector>
#include <algorithm>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) : n(size), tree(size + 2, 0) {}  // Using size + 2 to avoid index issues

    void update(int index, int delta) {
        for (; index <= n; index += index & -index) {
            tree[index] += delta;
        }
    }

    int query(int index) {
        int res = 0;
        for (; index > 0; index -= index & -index) {
            res += tree[index];
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos2(n);
        for (int i = 0; i < n; ++i) {
            pos2[nums2[i]] = i + 1;  // 1-based indexing
        }
        
        vector<int> seq(n);
        for (int i = 0; i < n; ++i) {
            seq[i] = pos2[nums1[i]];
        }
        
        FenwickTree ft(n);
        vector<int> left(n);
        for (int i = 0; i < n; ++i) {
            left[i] = ft.query(seq[i] - 1);
            ft.update(seq[i], 1);
        }
        
        FenwickTree ft_right(n);
        long long res = 0;
        for (int i = n - 1; i >= 0; --i) {
            int right = ft_right.query(n) - ft_right.query(seq[i]);
            res += (long long)left[i] * right;
            ft_right.update(seq[i], 1);
        }
        
        return res;
    }
};