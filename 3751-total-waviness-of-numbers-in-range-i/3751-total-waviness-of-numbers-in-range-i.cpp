class Solution {
public:
    using ll = long long;

    struct Node {
        ll ways;
        ll waviness;
    };

    string s;

    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    Node solve(int pos, int prev1, int prev2, bool tight, bool started) {
        if (pos == s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][prev1][prev2][started][0]) {
            return dp[pos][prev1][prev2][started][0];
        }

        int limit = tight ? s[pos] - '0' : 9;

        ll totalWays = 0;
        ll totalWave = 0;

        for (int d = 0; d <= limit; d++) {

            bool newStarted = started || (d != 0);

            int nprev1 = prev1;
            int nprev2 = prev2;

            ll add = 0;

            if (!newStarted) {
                nprev1 = 10;
                nprev2 = 10;
            } else {
                if (!started) {
                    nprev1 = d;
                    nprev2 = 10;
                } else if (prev2 == 10) {
                    nprev2 = prev1;
                    nprev1 = d;
                } else {

                    int a = prev2;
                    int b = prev1;
                    int c = d;

                    if ((b > a && b > c) ||
                        (b < a && b < c)) {
                        add = 1;
                    }

                    nprev2 = prev1;
                    nprev1 = d;
                }
            }

            Node nxt = solve(
                pos + 1,
                nprev1,
                nprev2,
                tight && (d == limit),
                newStarted
            );

            totalWays += nxt.ways;
            totalWave += nxt.waviness + add * nxt.ways;
        }

        Node ans = {totalWays, totalWave};

        if (!tight) {
            vis[pos][prev1][prev2][started][0] = true;
            dp[pos][prev1][prev2][started][0] = ans;
        }

        return ans;
    }

    long long calc(long long n) {
        if (n < 0) return 0;

        s = to_string(n);

        memset(vis, 0, sizeof(vis));

        return solve(0, 10, 10, 1, 0).waviness;
    }

    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};