#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0), vec;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vec.push_back(i);
            queue<int> q;
            q.push(i);
            vis[i] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (vis[v]) continue;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    cout << vec.size() - 1 << endl;
    for (int i = 0; i < vec.size() - 1; i++) {
        cout << vec[i] << ' ' << vec[i + 1] << endl;
    }
}
