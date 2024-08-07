
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
bool flag = true;
vector<vector<int>> adj;
unordered_map<int, int> group;

void dfs(int u, int g) {
    if (!flag) {
        return;
    }
    group[u] = g;
    for (auto v : adj[u]) {
        if (!group.count(v)) {
            dfs(v, 1 - g);
        } else if (group[v] == g) {
            flag = false;
            return;
        }
    }
}

void solve() {
    cin >> n >> m;
    adj.resize(n + 1, {});
    group.clear();
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    flag = true;
    for (int i = 1; i <= n; i++) {
        if (!group.count(i)) {
            dfs(i, 0);
        }
    }
    if (!flag) {
        cout << "IMPOSSIBLE";
        return;
    }
    for (int i = 1; i <= n; i++) {
        cout << group[i] + 1 << ' ';
    }
}

signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}
