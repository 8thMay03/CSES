/*
    Author: kamine
    Created: 2025-02-28 15:06:28
*/
#include <bits/stdc++.h>

#define int long long

using namespace std;

// a^(b^c) mod m = a^(b^c mod (m-1)) mod m

const int m = 1e9 + 7;

int pow(int a, int b, int mod) {
    if (a == 0 && b == 0) return 1;
    if (b == 0) return 1;
    int x = pow(a, b >> 1, mod);
    x = x * x % mod;
    if (b % 2) x = x * a % mod;
    return x;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << pow(a, pow(b, c, m - 1), m) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}