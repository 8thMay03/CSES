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
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    map<int, int> mp;
    mp[0] = 1;
    int sum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans += mp[sum - k];
        mp[sum]++;
    }
    cout << ans;
}
 
signed main() {
    faster();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}