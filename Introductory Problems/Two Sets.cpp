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
    if(n % 4 == 1 or n % 4 == 2) cout << "NO";
    else if(n % 4 == 0){
        vi a, b;
        for(int i = 1; i <= n; i += 4){
            a.pb(i);
            a.pb(i + 3);
            b.pb(i + 1);
            b.pb(i + 2);
        }
        cout << "YES\n" << a.size() << endl << a << endl << b.size() << endl << b;
    }
    else if(n % 4 == 3){
        vi a, b;
        a.pb(1);
        a.pb(2);
        b.pb(3);
        for(int i = 4; i <= n; i += 4){
            a.pb(i);
            a.pb(i + 3);
            b.pb(i + 1);
            b.pb(i + 2);
        }
        cout << "YES\n" << a.size() << endl << a << endl << b.size() << endl << b;
    }
}