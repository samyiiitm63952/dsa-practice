class Solution {
public:
    int dp[301][27][27];

    int getDist(int ch, int pos) {
        if (pos == -1) return 0;
        int x1 = ch / 6, y1 = ch % 6;
        int x2 = pos / 6, y2 = pos % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int helper(string &word, int i, int pos1, int pos2) {
        if (i == word.size()) return 0;

        int &res = dp[i][pos1 + 1][pos2 + 1];
        if (res != -1) return res;

        int ch = word[i] - 'A';

        // move finger1
        int d1 = getDist(ch, pos1) + helper(word, i + 1, ch, pos2);

        // move finger2
        int d2 = getDist(ch, pos2) + helper(word, i + 1, pos1, ch);

        return res = min(d1, d2);
    }

    int minimumDistance(string word) {
        memset(dp, -1, sizeof(dp));
        return helper(word, 0, -1, -1);
    }
};