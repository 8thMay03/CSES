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

const int mod = 1e9 + 7;

int inverse(int n) {
    if (n == 1) {
        return 1;
    }
    return (mod - ((mod / n) * inverse(mod % n)) % mod + mod) % mod;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> factorial(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        factorial[i] *= factorial[i - 1] * i;
        factorial[i] %= mod;
    }
    unordered_map<char, int> mp;
    for (char c : s) {
        mp[c]++;
    }
    int ans = factorial[n];
    for (auto [k, v] : mp) {
        ans *= inverse(factorial[v]);
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