#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), pos(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int rounds = 1;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i + 1]) rounds++;
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        int u = a[x], v = a[y];
        set<pair<int,int>> S;

        for (int k : {u, v}) {
            if (k > 1) S.emplace(k - 1, k);
            if (k < n) S.emplace(k, k + 1);
        }

        for (auto [p, q] : S) {
            if (pos[p] > pos[q]) rounds--;
        }

        swap(a[x], a[y]);
        pos[u] = y;
        pos[v] = x;

        for (auto [p, q] : S) {
            if (pos[p] > pos[q]) rounds++;
        }

        cout << rounds << '\n';
    }

    return 0;
}
