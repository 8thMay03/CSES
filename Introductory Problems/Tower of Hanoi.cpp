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
 
void Try(int n, int a, int b, int c){
    if(n == 1)
        cout << a << " " << c << endl;
    else{
        Try(n - 1, a, c, b);
        Try(1, a, b, c);
        Try(n - 1, b, a, c);
    }
}
 
int main(){
    faster();
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    Try(n, 1, 2, 3);
}