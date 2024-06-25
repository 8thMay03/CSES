#include <bits/stdc++.h>
 
#define int long long
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define faster() ios::sync_with_stdio(false); cin.tie(0);
#define pi 3.14159265358979323846
#define N 1000005
 
using namespace std;
 
template <typename T> istream& operator >> (istream& in, vector<T>& vec) {for (T& element : vec) in >> element; return in;}
template <typename T> ostream& operator << (ostream& out, vector<T>& vec) {for (T& element : vec) out << element << " "; return out;}
template <typename T> ostream& operator << (ostream& out, set<T>& st) {for (const T& element : st) out << element << " "; return out;}
 
int n, q;
int a[N];
 
void build() {
    for (int i = n - 1; i > 0; i--) {
        a[i] = min(a[i << 1], a[i << 1 | 1]);
    }
}
 
int query(int l, int r) {
    int res = 1e18;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            res = min(res, a[l++]);
        }
        if (r & 1) {
            res = min(res, a[--r]);
        }
    }
    return res;
}
 
void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[n + i];
    }
    build();
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l - 1, r) << endl;
    }
}
 
signed main() {
    faster();
    solve();
}