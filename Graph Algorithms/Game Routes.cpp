#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1], in(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
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

    vector<int> dp(n + 1);
    dp[1] = 1;
    for (int u : topo) {
        if (dp[u] == 0) continue;
        for (int v : adj[u]) {
            dp[v] = (dp[u] + dp[v]) % MOD;
        }
    }

    cout << dp[n];
}
