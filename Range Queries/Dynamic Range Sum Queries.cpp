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

class SumSegmentTree {
public:
    int n;
    vector<int> sg;
    
    void build() {
        for (int i = n - 1; i > 0; i--) {
            sg[i] = sg[i << 1] + sg[i << 1 | 1];
        }
    }

    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += sg[l++];
            if (r & 1) res += sg[--r];
        }
        return res;
    }

    void update(int i, int x) {
        for (sg[i += n] = x; i > 1; i >>= 1) {
            sg[i >> 1] = sg[i] + sg[i ^ 1];
        }
    }

    SumSegmentTree (vector<int> a) {
        this->n = a.size();
        sg.resize(4 * n);
        for (int i = n; i < 2 * n; i++) {
            sg[i] = a[i - n];
        }
        build();
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    cin >> a;
    SumSegmentTree tree(a);
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            tree.update(y - 1, z);
        } else {
            cout << tree.query(y - 1, z) << endl;
        }
    }
}

signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}   