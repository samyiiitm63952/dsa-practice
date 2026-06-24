class Solution {
public:
    static const int MOD = 1e9+7;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(Matrix &A, Matrix &B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();
        Matrix result(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) result[i][i] = 1;

        while (exp) {
            if (exp & 1) result = multiply(result, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return result;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        int size = 2 * m;
        Matrix T(size, vector<long long>(size, 0));

        // DOWN: 0..m-1
        // UP:   m..2m-1

        for (int x = 0; x < m; x++) {
            // DOWN[x] -> UP[y] where y > x
            for (int y = x + 1; y < m; y++) {
                T[m + y][x] = 1;
            }

            // UP[x] -> DOWN[y] where y < x
            for (int y = 0; y < x; y++) {
                T[y][m + x] = 1;
            }
        }

        Matrix T_exp = power(T, n - 1);

        vector<long long> init(size, 1); // both UP and DOWN = 1

        vector<long long> result(size, 0);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i] = (result[i] + T_exp[i][j] * init[j]) % MOD;
            }
        }

        long long ans = 0;
        for (auto x : result) ans = (ans + x) % MOD;

        return ans;
    }
};