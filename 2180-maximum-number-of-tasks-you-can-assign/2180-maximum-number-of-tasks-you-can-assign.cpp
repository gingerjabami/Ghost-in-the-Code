class Solution {
public:
 bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> workerSet(workers.end() - k, workers.end()); 
        int usedPills = 0;

        for (int i = k - 1; i >= 0; --i) { 
            int task = tasks[i];

       
            auto it = prev(workerSet.end());
            if (*it >= task) {
                workerSet.erase(it);
            } else {
                
                it = workerSet.lower_bound(task - strength);
                if (it == workerSet.end()) return false;
                workerSet.erase(it);
                usedPills++;
                if (usedPills > pills) return false;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
         sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min(tasks.size(), workers.size()), ans = 0;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};