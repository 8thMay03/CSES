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
#define mii map<int, int>
#define mll map<ll, ll>
#define faster() ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

template <typename T> istream& operator>>(istream& in, vector<T>& vec){for (T& element : vec) in >> element; return in;}
template <typename T> ostream& operator<<(ostream& out, vector<T>& vec){for (T& element : vec) out << element << " "; return out;}
template <typename T> ostream& operator<<(ostream& out, set<T>& st){for (const T& element : st) out << element << " "; return out;}

int main(){
    faster();
    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    sort(all(a));
    ll ans = 1;
    for(int i = 0; i < n; i++){     // Nếu prefixSum[i - 1] < a[i + 1] thì số nhỏ nhất không thế tạo ra là prefixSum[i - 1] + 1
        if(ans < a[i]) break;
        ans += a[i];
    }
    cout << ans;
}