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
    int n, x;
    cin >> n >> x;
    vi a(n);
    vll dp(x + 1, 1e9);
    cin >> a;
    for(int i: a) if(i <= x) dp[i] = 1;
    for(int i = 1; i <= x; i++){
        if(dp[i] == 1) continue;
        for(int j: a){
            if(i >= j) dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }
    if(dp[x] == 1e9) cout << -1;
    else cout << dp[x];
}