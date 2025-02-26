/*
    Author: kamine
    Created: 2025-02-26 14:28:40
*/
#include <bits/stdc++.h>

using namespace std;

// Check if the graph is strongly connected: There is a path between 1 and i for all i from 1 to n and vice versa.

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1), rev_adj(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    vector<bool> vis(n + 1);
    vis[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << 1 << " " << i << "\n";
            return 0;
        }
    }

    fill(vis.begin(), vis.end(), false);
    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : rev_adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO\n";
            cout << i << " " << 1 << "\n";
            return 0;
        }
    }

    cout << "YES\n";
}