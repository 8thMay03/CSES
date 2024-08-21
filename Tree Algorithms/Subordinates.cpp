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
 
template <typename T> istream& operator >> (istream& in, vector<T>& vec) {for (T& element : vec) in >> element; return in;}
template <typename T> ostream& operator << (ostream& out, vector<T>& vec) {for (T& element : vec) out << element << " "; return out;}
template <typename T> ostream& operator << (ostream& out, set<T>& st) {for (const T& element : st) out << element << " "; return out;}

map<int, int> mp;
vector<vector<int>> adj;

void dfs(int u) {
    for (int v : adj[u]) {
        dfs(v);
        mp[u] += mp[v] + 1;
    }
}
 
void solve() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << mp[i] << " ";
    }
}
 
signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}