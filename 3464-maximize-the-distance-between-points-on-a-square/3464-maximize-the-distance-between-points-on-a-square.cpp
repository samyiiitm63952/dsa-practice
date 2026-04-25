class Solution {
    struct P {
        long long pos, x, y;
    };

    long long getOffset(long long s, long long x, long long y, long long d) {
        if (x == 0) { // left
            if (d <= 2*s - y) return d;
            if (d <= s + y) return 2*s + d - 2*y;
        } 
        else if (y == s) { // top
            if (d <= 2*s - x) return d;
            if (d <= s + x) return 2*s + d - 2*x;
        } 
        else if (x == s) { // right
            if (d <= s + y) return d;
            if (d <= 2*s - y) return d + 2*y;
        } 
        else { // bottom
            if (d <= s + x) return d;
            if (d <= 2*s - x) return d + 2*x;
        }
        return -1;
    }

    bool can(long long side, vector<P>& pts, int k, long long d) {
        int n = pts.size();

        vector<long long> pos3(3*n);
        for (int i = 0; i < n; i++) {
            pos3[i] = pts[i].pos;
            pos3[i+n] = pts[i].pos + 4LL*side;
            pos3[i+2*n] = pts[i].pos + 8LL*side;
        }

        vector<int> nxt(2*n, -1);

        for (int i = 0; i < 2*n; i++) {
            auto &p = pts[i % n];
            long long off = getOffset(side, p.x, p.y, d);
            if (off < 0) continue;

            long long target = pos3[i] + off;
            int hi = min(i + n, 3*n);

            auto it = lower_bound(pos3.begin() + i + 1, pos3.begin() + hi, target);
            if (it != pos3.begin() + hi)
                nxt[i] = it - pos3.begin();
        }

        for (int start = 0; start < n; start++) {
            int cur = start, cnt = 1;

            while (cnt < k) {
                cur = nxt[cur];
                if (cur == -1 || cur >= start + n) break;
                cnt++;
            }

            if (cnt >= k) {
                long long dx = llabs(pts[start].x - pts[cur % n].x);
                long long dy = llabs(pts[start].y - pts[cur % n].y);
                if (dx + dy >= d) return true;
            }
        }
        return false;
    }

public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<P> pts;
        pts.reserve(points.size());

        for (auto &v : points) {
            long long x = v[0], y = v[1];
            long long pos;

            if (x == 0) pos = y;
            else if (y == side) pos = side + x;
            else if (x == side) pos = 3LL*side - y;
            else pos = 4LL*side - x;

            pts.push_back({pos, x, y});
        }

        sort(pts.begin(), pts.end(), [](const P &a, const P &b) {
            return a.pos < b.pos;
        });

        long long lo = 0, hi = 2LL * side;

        while (lo < hi) {
            long long mid = (lo + hi + 1) >> 1;
            if (can(side, pts, k, mid)) lo = mid;
            else hi = mid - 1;
        }

        return (int)lo;
    }
};