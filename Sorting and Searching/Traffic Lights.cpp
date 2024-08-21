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

template <typename T> 
istream& operator >> (istream& in, vector<T>& vec) {for (T& element : vec) in >> element; return in;}
template <typename T> ostream& operator << (ostream& out, vector<T>& vec) {for (T& element : vec) out << element << " "; return out;}
template <typename T> ostream& operator << (ostream& out, set<T>& st) {for (const T& element : st) out << element << " "; return out;}

void solve() {
    int x, n;
    cin >> x >> n;

    set<int> pos;   // stores the position of the lights
    pos.insert(0);
    pos.insert(x);

    multiset<int> len; // stores the length of the segments
    len.insert(x);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        pos.insert(p);
        auto it = pos.find(p);   // current light position
        int nextVal = *next(it); // next light position
        int prevVal = *prev(it); // previous light position
        // When we insert a new light, we create two new segments 
        // in place of one, so we need to remove the old segment and insert the new segments

        len.erase(len.find(nextVal - prevVal)); // remove the old segment
        len.insert(p - prevVal);    // insert the new segments
        len.insert(nextVal - p);    // insert the new segments

        cout << *len.rbegin() << " ";
    }
}

signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}