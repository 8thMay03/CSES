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

int main(){
    faster();
    int n;
    cin >> n;
    int ans = 0;
    while(n > 0){       // Greedy solution, always pick the largest number to subtract 
        string s = to_string(n);
        int mx = *max_element(all(s)) - '0';
        n -= mx;
        ans++;
    }
    cout << ans;
}

// DynamicDynamic Programming solution
// int main(){
//     faster();
//     int n;
//     cin >> n;
//     vi dp(n + 1, 1e9);
//     dp[n] = 0;
//     for(int i = n; i >= 0; i--){
//         for(char c : to_string(i)){
//             dp[i - (c - '0')] = min(dp[i - (c - '0')], dp[i] + 1);
//         }
//     }
//     cout << dp[0];
// }