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

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    if (a[0] == 0) {
        fill(dp[0].begin(), dp[0].end(), 1);
    } else {
        dp[0][a[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == 0) {
            for (int j = 1; j <= m; j++) {
                for (int k : {j - 1, j, j + 1}) {
                    if (k >= 1 && k <= m) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                    }
                }
            }
        } else {
            for (int k : {a[i] - 1, a[i], a[i] + 1}) {
                if (k >= 1 && k <= m) {
                    dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][k]) % mod;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[n - 1][i];
        ans %= mod;
    }
    cout << ans << endl;
}

signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}