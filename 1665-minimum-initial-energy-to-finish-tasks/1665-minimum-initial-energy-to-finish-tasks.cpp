class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b) {

        return (a[1] - a[0]) > (b[1] - b[0]);
    }

    bool canFinish(int energy, vector<vector<int>>& tasks) {

        for(auto& task : tasks) {

            int actual = task[0];
            int minimum = task[1];

            if(energy < minimum) {
                return false;
            }

            energy -= actual;
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {

        sort(tasks.begin(), tasks.end(), cmp);

        int low = 1;
        int high = 1e9;

        int ans = high;

        while(low <= high) {

            int mid = low + (high - low)/2;

            if(canFinish(mid, tasks)) {

                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};