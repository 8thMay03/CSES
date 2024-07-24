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
    int n;
    cin >> n;
    vector<int> a(n);
    int high = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        high = max(a[i], high);
    }
    vector<int> mp(high + 1, 0);
    for (int i : a) {
        mp[i]++;
    }
    for (int i = high; i >= 1; i--) {
        int j = i;
        int cnt = 0;
        while (j <= high) {
            if (mp[j] > 1) {
                cout << j << endl;
                return;
            }
            if (mp[j] == 1) {
                cnt++;
            }
            if (cnt == 2) {
                cout << i << endl;
                return;
            }
            j += i;
        }
    }
    cout << 1 << endl;
}

signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}