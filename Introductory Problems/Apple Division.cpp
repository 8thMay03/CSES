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

int n;
vi a;
ll sum = 0, tmp = 0, ans = LLONG_MAX;

void Try(int i){
    for(int j = 0; j <= 1; j++){
        tmp += (j * a[i]);
        if(i == n - 1) ans = min(ans, abs(sum - 2 * tmp));
        else Try(i + 1);
        tmp -= (j * a[i]);
    }
}

int main(){
    faster();
    cin >> n;
    a.resize(n);
    cin >> a;
    for(int i : a) sum += i;
    Try(0);
    cout << ans;
}