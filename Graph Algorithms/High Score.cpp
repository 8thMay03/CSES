/*
    Author: kamine
    Created: 2024-09-23 10:13:41
*/
#include <bits/stdc++.h>

#define int long long

using namespace std;

const int INF = 1e18;

struct Edge {
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    vector<int> d(n + 1, -INF);
    d[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto e : edges) {
            int u = e.u;
            int v = e.v;
            int w = e.w;
            if (d[u] != -INF && d[v] < d[u] + w) {
                d[v] = d[u] + w;
            }
        }
    }
    vector<bool> positive_cycle(n + 1, false);
    for (int i = 0; i < n; i++) {
        for (auto e : edges) {
            int u = e.u;
            int v = e.v;
            int w = e.w;
            if (d[u] != -INF && d[v] < d[u] + w) {
                d[v] = INF;
                positive_cycle[v] = true;
            }
        }
    }
    if (d[n] == -INF) {
        cout << -1 << endl;
    }
    else if (positive_cycle[n]) {
        cout << -1 << endl;
    }
    else {
        cout << d[n] << endl;
    }

}