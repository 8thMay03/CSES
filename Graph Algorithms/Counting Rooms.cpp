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
 
 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
vs s;
 
void dfs(int i, int j){
    s[i][j] = '#';
    for(int k = 0; k < 4; k++){
        int ii = i + dx[k];
        int jj = j + dy[k];
        if(ii < n and ii >= 0 and jj < m and jj >= 0 and s[ii][jj] != '#'){
            dfs(ii, jj);
        }
    }
}
 
int main(){
    faster();
    cin >> n >> m;
    s.resize(n);
    cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] != '#'){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
}