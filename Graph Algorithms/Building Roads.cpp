#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define faster() ios::sync_with_stdio(false); cin.tie(0);
#define pi 3.14159265358979323846
#define N 1000005

using namespace std;

template<typename T>
istream &operator >>(istream &in, vector<T> &vec) {
    for (T &element: vec) in >> element;
    return in;
}

template<typename T>
ostream &operator <<(ostream &out, vector<T> &vec) {
    for (T &element: vec) out << element << " ";
    return out;
}

template<typename T>
ostream &operator <<(ostream &out, set<T> &st) {
    for (const T &element: st) out << element << " ";
    return out;
}

int n, m;
vector<vector<int>> adj, groups;
vector<bool> vis;

void dfs(int u, vector<int>& group) {
    vis[u] = true;
    group.push_back(u);
    for (auto v : adj[u]) {
        if (!vis[v]) {
            dfs(v, group);
        }
    }
}

void solve() {
    cin >> n >> m;
    adj.resize(n + 1, {});
    vis.resize(n + 1, false);
    groups.resize(0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vector<int> group;
            dfs(i, group);
            groups.push_back(group);
        }
    }
    cout << groups.size() - 1 << endl;
    for (int i = 0; i < groups.size() - 1; i++) {
        cout << groups[i][0] << ' ' << groups[i + 1][0] << endl;
    }
}

signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}
