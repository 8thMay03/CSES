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
 
const ll mod = 1e9 + 7;
 
int main(){
    faster();
    ll n, k;
    cin >> n >> k;
    vll a(n);
    cin >> a;
    vll dp(k + 1, 0);
    dp[0] = 1;
    for(ll i = 0; i < n; i++){
        for(ll j = 1; j <= k; j++){
            if(j >= a[i]){
                dp[j] += dp[j - a[i]];
                dp[j] %= mod;
            }
        }
    }
    cout << dp[k];
}