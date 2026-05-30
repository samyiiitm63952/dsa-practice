class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    void update(int node, int l, int r,
                int idx, int val) {

        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r,
                   idx, val);

        tree[node] = max(tree[2 * node],
                         tree[2 * node + 1]);
    }

    int query(int node, int l, int r,
              int ql, int qr) {

        if (qr < l || r < ql)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return max(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r,
                  ql, qr)
        );
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int MAXX = 50005;

        set<int> obs;
        obs.insert(0);
        obs.insert(MAXX);

        SegmentTree seg(MAXX + 1);

        seg.update(1, 0, MAXX, MAXX, MAXX);

        vector<bool> ans;

        for (auto &q : queries) {

            if (q[0] == 1) {

                int x = q[1];

                auto it = obs.upper_bound(x);

                int right = *it;
                int left = *prev(it);

                seg.update(1, 0, MAXX,
                           right,
                           right - x);

                seg.update(1, 0, MAXX,
                           x,
                           x - left);

                obs.insert(x);
            }

            else {

                int x = q[1];
                int sz = q[2];

                auto it = obs.upper_bound(x);

                int left = *prev(it);

                int best =
                    seg.query(1, 0, MAXX,
                              0, left);

                best = max(best, x - left);

                ans.push_back(best >= sz);
            }
        }

        return ans;
    }
};