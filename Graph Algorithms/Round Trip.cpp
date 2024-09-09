/*
    Author: kamine
    Created: 2024-09-03 08:36:17
*/
#include <bits/stdc++.h>

using namespace std;

int n, m, flag = 0;
vector<int> adj[100001], par(100001), vis(100001);
        
void dfs(int u, int p) {
    vis[u] = 1;
    par[u] = p;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v, u);
        } else if (v != p) {
            vector<int> path;
            for (int x = u; x != v; x = par[x]) {
                path.push_back(x);
            }
            path.push_back(v);
            path.push_back(u);
            cout << path.size() << '\n';
            for (int x : path) {
                cout << x << ' ';
            }
            flag = 1;
            exit(0);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!flag) {
            if (!vis[i]) {
                dfs(i, 0);
            }
        } else {
            break;
        }
    }
    if (!flag) {
        cout << "IMPOSSIBLE\n";
    }
}