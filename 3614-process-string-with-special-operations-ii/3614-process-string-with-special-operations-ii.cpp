class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z')
                len[i + 1] = len[i] + 1;
            else if (ch == '*')
                len[i + 1] = max(0LL, len[i] - 1);
            else if (ch == '#')
                len[i + 1] = len[i] * 2;
            else // '%'
                len[i + 1] = len[i];
        }

        if (k >= len[n]) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            long long prev = len[i];

            if ('a' <= ch && ch <= 'z') {
                if (k == prev) return ch;
            }
            else if (ch == '#') {
                if (prev > 0) k %= prev;
            }
            else if (ch == '%') {
                if (prev > 0)
                    k = prev - 1 - k;
            }
            // '*' needs no action
        }

        return '.';
    }
};