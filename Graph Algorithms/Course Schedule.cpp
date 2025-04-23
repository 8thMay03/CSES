/*
    Author: kamine
    Created: 2025-03-03 14:28:32
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1], in(n + 1, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        in[u]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }

    if (topo.size() != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int u : topo) {
            cout << u << ' ';
        }
        cout << '\n';
    }
}