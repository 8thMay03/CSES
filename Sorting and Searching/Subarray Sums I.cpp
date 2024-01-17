#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vector<vi>
#define vvl vector<vll>
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mii map<int, int>
#define mll map<ll, ll>
#define faster() ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

template <typename T> istream& operator >> (istream& in, vector<T>& vec) {for (T& element : vec) in >> element; return in;}
template <typename T> ostream& operator << (ostream& out, vector<T>& vec) {for (T& element : vec) out << element << " "; return out;}
template <typename T> ostream& operator << (ostream& out, set<T>& st) {for (const T& element : st) out << element << " "; return out;}

int main() {
    faster();
    int n, k;
    cin >> n >> k;
    vll a(n), pre(n);
    cin >> a;
    pre[0] = a[0];
    for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];
    set<ll> st;
    st.insert(0);
    int ans = 0;
    for (ll i : pre) {
        if (st.count(i - k)) ans++;
        st.insert(i);
    }
    cout << ans << endl;
}