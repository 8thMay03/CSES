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
 
void masking(vector<int> a, vector<int>& sum) { 
    int n = a.size();
    for (int mask = 0; mask < (1 << n); ++mask) {
        int subset_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                subset_sum += a[i];
            }
        }
        sum.push_back(subset_sum);
    }
    sort(all(sum));
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    vector<int> a1(a.begin(), a.begin() + n / 2), a2(a.begin() + n / 2, a.end());
    vector<int> sum1, sum2;
    masking(a1, sum1);
    masking(a2, sum2);
    int ans = 0;
    for (int x : sum1) {
        int it = lower_bound(all(sum2), m - x) - sum2.begin();
        if (it == sum2.size()) {
            continue;
        }
        if (sum2[it] != m - x) {
            continue;
        } 
        int it2 = upper_bound(all(sum2), m - x) - sum2.begin();
        ans += (it2 - it);
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