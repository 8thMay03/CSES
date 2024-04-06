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
#define rall(x) x.rbegin(), x.rend()
#define mii map<int, int>
#define mll map<ll, ll>
#define faster() ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

template <typename T> istream& operator >> (istream& in, vector<T>& vec) {for (T& element : vec) in >> element; return in;}
template <typename T> ostream& operator << (ostream& out, vector<T>& vec) {for (T& element : vec) out << element << " "; return out;}
template <typename T> ostream& operator << (ostream& out, set<T>& st) {for (const T& element : st) out << element << " "; return out;}

vector<string> s(8);
vector<bool> di1(15, false), di2(15, false), col(8, false);
int ans = 0;

void Try(int i) {
    for (int j = 0; j < 8; j++) {
        if (s[i][j] == '.') {
            if (!col[j] and !di1[7 - i + j] and !di2[i + j]) {
                col[j] = true;
                di1[7 - i + j] = true;
                di2[i + j] = true;
                if (i == 7) {
                    ans++;
                } else if (i < 7) {
                    Try(i + 1);
                }
                col[j] = false;
                di1[7 - i + j] = false;
                di2[i + j] = false;
            }
        }
    }
}

int main() {
    faster();
    cin >> s;
    Try(0);
    cout << ans;
}