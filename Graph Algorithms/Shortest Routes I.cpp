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

const int INF = 1e18; // Sufficiently large value to act as infinity
int n, m;
vector<vector<pii>> adj;

void dijkstra(int u) {
    vector<int> dist(n + 1, INF);
    vector<bool> vis(n + 1, false);
    dist[u] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.emplace(0, u);
    while (!q.empty()) {
        int cur = q.top().se;
        q.pop();

        if (vis[cur]) continue; // Skip if already visited

        vis[cur] = true;
        for (auto [v, w] : adj[cur]) {
            if (dist[cur] + w < dist[v]) {
                dist[v] = dist[cur] + w;
                q.emplace(dist[v], v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
}

void solve() {
    cin >> n >> m;
    adj.resize(n + 1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    dijkstra(1);
}

signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}
