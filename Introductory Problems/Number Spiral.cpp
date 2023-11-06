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
    int t;
    cin >> t;
    while(t--){
        ll x, y, ans;
        cin >> x >> y;
        ll mx = max(x, y);
        ll mn = min(x, y);
        if(mx == x){
            if(x&1) ans = (mx - 1) * (mx - 1) + mn;
            else ans = mx * mx - mn + 1;
        }
        else{
            if(y % 2 == 0) ans = (mx - 1) * (mx - 1) + mn;
            else ans = mx * mx - mn + 1;
        }
        cout << ans << endl;
    }
}