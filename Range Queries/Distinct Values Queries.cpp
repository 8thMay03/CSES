/*
    Author: kamine
    Created: 2025-07-23 14:38:17
*/
#include <bits/stdc++.h>

using namespace std;

struct Query {
    int l, r, idx;
    Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
};

// Nén số
vector<int> compress(vector<int> a) {
    vector<int> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    vector<int> res(a.size());
    for (int i = 0; i < a.size(); ++i) {
        res[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& i : a) {
        cin >> i;
    }
    a = compress(a);
    vector<Query> queries;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        queries.push_back({l, r, i});
    }
    int block_size = sqrt(n);
    sort(queries.begin(), queries.end(), [&] (Query q1, Query q2) {
        if (q1.l / block_size != q2.l / block_size) {
            return q1.l / block_size < q2.l / block_size;
        }
        return q1.r < q2.r;
    });
    vector<int> cnt(n, 0), ans(q);
    int distinct = 0, L = 0, R = -1;
    for (auto [l, r, idx] : queries) {
        while (R < r) {
            R++;
            cnt[a[R]]++;
            if (cnt[a[R]] == 1) {
                distinct++;
            }
        }
        while (R > r) {
            cnt[a[R]]--;
            if (cnt[a[R]] == 0) {
                distinct--;
            }
            R--;
        }
        while (L > l) {
            L--;
            cnt[a[L]]++;
            if (cnt[a[L]] == 1) distinct++;
        }
        while (L < l) {
            cnt[a[L]]--;
            if (cnt[a[L]] == 0) distinct--;
            L++;
        }
        ans[idx] = distinct;
    }
    for (int x : ans) {
        cout << x << '\n';
    }
}
