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

int mod = 1e9 + 7;

vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> c(2, vector<int>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return c;
}

vector<vector<int>> pow(vector<vector<int>> a, int n) {
    if (n == 1) {
        return a;
    }
    if (n % 2 == 1) {
        return mul(a, pow(a, n - 1));
    }
    vector<vector<int>> b = pow(a, n / 2);
    return mul(b, b);
}

int fib(int n) {
    if (n == 0) {
        return 0;
    }
    vector<vector<int>> a = {{1, 1}, {1, 0}};
    a = pow(a, n);
    return a[0][1];
}

void solve() {
    int n;
    cin >> n;
    cout << fib(n);
}

signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}