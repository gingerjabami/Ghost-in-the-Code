class Solution {
public:
    int countLargestGroup(int n) {
          vector<int> count(37, 0); 

        for (int i = 1; i <= n; ++i) {
            int sum = 0, num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            count[sum]++;
        }

        int maxSize = *max_element(count.begin(), count.end());
        int groups = 0;
        for (int c : count) {
            if (c == maxSize) groups++;
        }

        return groups;
    }
};