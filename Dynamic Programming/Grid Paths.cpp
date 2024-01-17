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

template <typename T> istream& operator >> (istream& in, vector<T>& vec){for (T& element : vec) in >> element; return in;}
template <typename T> ostream& operator << (ostream& out, vector<T>& vec){for (T& element : vec) out << element << " "; return out;}
template <typename T> ostream& operator << (ostream& out, set<T>& st){for (const T& element : st) out << element << " "; return out;}

const ll mod = 1e9 + 7;

int main(){
    faster();
    int n;
    cin >> n;
    vs a(n);
    cin >> a;
    if(a[0][0] == '*') {
        cout << 0;
        return 0;
    }
    vector<vll> dp(n, vll(n, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            if(a[i][j] == '*' or i + j == 0) continue;
            if(i > 0 and a[i - 1][j] != '*') {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mod;
            }
            if(j > 0 and a[i][j - 1] != '*') {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n - 1][n - 1];
}