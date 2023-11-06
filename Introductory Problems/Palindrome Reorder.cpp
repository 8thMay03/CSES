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
    string s;
    cin >> s;
    map<char, int> mp;
    for(char c: s) mp[c]++;
    if(mp.size() == 1){
        cout << s;
        return 0;
    }
    vc v;
    for(auto m: mp){
        if(m.se % 2) v.pb(m.fi);
    }
    if((s.size() % 2 == 0 and v.size() > 0) or (v.size() > 1)){
        cout << "NO SOLUTION";
        return 0;
    }
    string ans = "";
    for(auto m: mp){
        for(int i = 0; i < m.se / 2; i++){
            ans += m.fi;
        }
    }
    string tmp = ans;
    reverse(all(tmp));
    if(v.size()) ans = ans + v[0] + tmp;
    else ans = ans + tmp;
    cout << ans;
    return 0;
}