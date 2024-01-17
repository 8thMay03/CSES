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
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i + 1;
    }
    sort(all(a));
    vi ans;
    for (int i = 0; i < n - 3; i++) {
        if (ans.size()) break;
        for (int j = i + 1; j < n - 2; j++) {
            if (ans.size()) break; 
            int l = j + 1;
            int r = n - 1;
            while (l < r) {
                ll sum = 0LL + a[i].fi + a[j].fi + a[l].fi + a[r].fi;
                if (sum == k) {
                    ans = {a[i].se, a[j].se, a[l].se, a[r].se};
                    break;
                }
                else if (sum > k) r--;
                else l++;
            }
        }
    }
    if (ans.empty()) cout << "IMPOSSIBLE";
    else cout << ans;
}