#include <bits/stdc++.h>

#define int long long

using namespace std;

class SegmentTree {
public:
    vector<int> a, st;
    int n;

    SegmentTree(vector<int> a) : a(a) {
        n = a.size();
        st.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int id, int l, int r) {
        if (l == r) {
            st[id] = a[l];
            return;
        }
        int m = l + r >> 1;
        build(id << 1, l, m);
        build(id << 1 | 1, m + 1, r);
        st[id] = min(st[id << 1], st[id << 1 | 1]);
    }

    int get(int id, int l, int r, int u, int v) {
        if (v < l || u > r) return LLONG_MAX;
        if (l >= u && r <= v) {
            return st[id];
        }
        int m = l + r >> 1;
        return min(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, u, v;
    cin >> n >> u >> v;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }

    SegmentTree st(a);

    int ans = LLONG_MIN;
    for (int r = u; r <= n; r++) {
        int mn = st.get(1, 0, a.size() - 1, max(r - v, 0LL), r - u);
        ans = max(ans, a[r] - mn);
    }

    cout << ans;
}
