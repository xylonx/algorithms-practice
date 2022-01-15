#include <iostream>
#include <vector>

class SegmentTree {
private:
    inline int left_son(int p) { return p << 1; };
    inline int right_son(int p) { return (p << 1) + 1; };

    // tree node num: 2n
    std::vector<int> sums, min, max, lazy;

    // [s, t], root is p
    void build_up_tree(const std::vector<int> &arr, int s, int t, int p) {
        if (s == t) {
            sums[p] = arr[s];
            min[p]  = arr[s];
            max[p]  = arr[s];
            return;
        }
        int mid = s + (t - s) / 2;
        build_up_tree(arr, s, mid, left_son(p));
        build_up_tree(arr, mid + 1, t, right_son(p));

        sums[p] = sums[left_son(p)] + sums[right_son(p)];
        min[p]  = min[left_son(p)] + min[right_son(p)];
        max[p]  = max[left_son(p)] + max[right_son(p)];
    }

    // the query segment is [l, r]
    // the maintaining segment is [s, t]
    int get_sum(int l, int r, int s, int t, int p) {
        if (l <= s && r >= t) return sums[p];

        int mid = s + (t - s) / 2, sum = 0;
        if (lazy[p]) {
            sums[left_son(p)] += lazy[p] * (mid - s + 1);
            sums[right_son(p)] += lazy[p] * (t - mid);

            lazy[left_son(p)] += lazy[p];
            lazy[right_son(p)] += lazy[p];

            lazy[p] = 0;
        }

        if (l <= mid) sum += get_sum(l, r, s, mid, left_son(p));
        if (r > mid) sum += get_sum(l, s, mid + 1, t, right_son(p));
        return sum;
    }

    // the update segment is [l, r]
    // the maintaining segment is [s, t]
    void update(int l, int r, int c, int s, int t, int p) {
        if (l <= s && r >= t) {
            sums[p] += (t - s + 1) * c;
            lazy[p] += c;
            return;
        }
        int mid = s + (t - s) / 2;
        if (lazy[p] && s != t) {
            sums[left_son(p)] += lazy[p] * (mid - s + 1);
            sums[right_son(p)] += lazy[p] * (t - mid);

            lazy[left_son(p)] += lazy[p];
            lazy[right_son(p)] += lazy[p];

            lazy[p] = 0;
        }

        if (l <= mid) update(l, r, c, s, mid, left_son(p));
        if (r > mid) update(l, r, c, mid + 1, t, right_son(p));

        sums[p] = sums[left_son(p)] + sums[right_son(p)];
    }

public:
    SegmentTree(const std::vector<int> &arr) {
        int n = arr.size();
        sums.resize(n * 2);
        min.resize(n * 2);
        max.resize(n * 2);
        lazy.resize(n * 2);
        build_up_tree(arr, 0, n - 1, 1);
    }
};