
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

template<typename T>
istream &operator >>(istream &in, vector<T> &vec) {
    for (T &element: vec) in >> element;
    return in;
}

template<typename T>
ostream &operator <<(ostream &out, vector<T> &vec) {
    for (T &element: vec) out << element << " ";
    return out;
}

template<typename T>
ostream &operator <<(ostream &out, set<T> &st) {
    for (const T &element: st) out << element << " ";
    return out;
}

bool check(vector<int> a, int x, int k) {
    int sum = 0;
    for (int i : a) {
        sum += min(x / i, (int)1e9);
    }
    return sum >= k;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    int low = 0, high = 1e18;
    while (low < high) {
        int mid = (low + high) / 2;
        if (check(a, mid, k)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
}

signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}
