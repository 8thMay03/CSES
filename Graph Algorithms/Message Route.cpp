#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vector<vi>
#define vvl vector<vll>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mii map<int, int>
#define mll map<ll, ll>
#define faster() ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

template <typename T> istream& operator >> (istream& in, vector<T>& vec) {for (T& element : vec) in >> element; return in;}
template <typename T> ostream& operator << (ostream& out, vector<T>& vec) {for (T& element : vec) out << element << " "; return out;}
template <typename T> ostream& operator << (ostream& out, set<T>& st) {for (const T& element : st) out << element << " "; return out;}

int main() {
    faster();
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n + 1), pre(n + 1, 0), ans;
    bool found = false;
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (q.size()) {
        if (found) break;
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v]) {
                pre[v] = u;
                if (v == n) {
                    found = true;
                    break;
                }
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    if (!found) cout << "IMPOSSIBLE";
    else {
        int tmp = n;
        while (tmp != 0) {
            ans.push_back(tmp);
            tmp = pre[tmp];
        }
        reverse(all(ans));
        cout << ans.size() << endl << ans;
    }
}