class Solution {
public:
    using ll = long long;

    vector<vector<int>> stMax, stMin;
    vector<int> lg;

    void buildSparse(vector<int>& nums) {
        int n = nums.size();

        lg.resize(n + 1);
        lg[1] = 0;

        for (int i = 2; i <= n; i++) {
            lg[i] = lg[i / 2] + 1;
        }

        int K = lg[n] + 1;

        stMax.assign(K, vector<int>(n));
        stMin.assign(K, vector<int>(n));

        for (int i = 0; i < n; i++) {
            stMax[0][i] = nums[i];
            stMin[0][i] = nums[i];
        }

        for (int k = 1; k < K; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {

                stMax[k][i] = max(
                    stMax[k - 1][i],
                    stMax[k - 1][i + (1 << (k - 1))]
                );

                stMin[k][i] = min(
                    stMin[k - 1][i],
                    stMin[k - 1][i + (1 << (k - 1))]
                );
            }
        }
    }

    int rangeMax(int l, int r) {
        int j = lg[r - l + 1];

        return max(
            stMax[j][l],
            stMax[j][r - (1 << j) + 1]
        );
    }

    int rangeMin(int l, int r) {
        int j = lg[r - l + 1];

        return min(
            stMin[j][l],
            stMin[j][r - (1 << j) + 1]
        );
    }

    ll getValue(int l, int r) {
        return 1LL * rangeMax(l, r) - rangeMin(l, r);
    }

    long long maxTotalValue(vector<int>& nums, int k) {

        int n = nums.size();

        buildSparse(nums);

        // {value, l, r}
        priority_queue<tuple<ll,int,int>> pq;

        for (int l = 0; l < n; l++) {
            pq.push({
                getValue(l, n - 1),
                l,
                n - 1
            });
        }

        ll ans = 0;

        while (k--) {

            auto [val, l, r] = pq.top();
            pq.pop();

            ans += val;

            if (r > l) {
                pq.push({
                    getValue(l, r - 1),
                    l,
                    r - 1
                });
            }
        }

        return ans;
    }
};