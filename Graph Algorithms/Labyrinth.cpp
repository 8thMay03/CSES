#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define faster() ios::sync_with_stdio(false); cin.tie(0);
#define pi 3.14159265358979323846
#define N 1000005

using namespace std;

template <typename T> istream& operator >> (istream& in, vector<T>& vec) {for (T& element : vec) in >> element; return in;}
template <typename T> ostream& operator << (ostream& out, vector<T>& vec) {for (T& element : vec) out << element << " "; return out;}
template <typename T> ostream& operator << (ostream& out, set<T>& st) {for (const T& element : st) out << element << " "; return out;}

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<char> moves = {'U', 'D', 'L', 'R'};

void solve() {
    int n, m;
    cin >> n >> m;
    char s[n][m];
    pair<int, int> start, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
            if (s[i][j] == 'A') {
                start.fi = i;
                start.se = j;
            }
            if (s[i][j] == 'B') {
                end.fi = i;
                end.se = j;
            }
        }
    }
    map<pair<int, int>, pair<int, int>> pre;
    queue<pair<int, int>> q;
    q.push({start});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {cur.fi + dx[i], cur.se + dy[i]};
            if (next.fi >= 0 && next.fi < n && next.se >= 0 && next.se < m && s[next.fi][next.se] != '#') {
                s[next.fi][next.se] = '#';
                pre[next] = cur;
                if (next == end) {
                    vector<pair<int, int>> path;
                    while (end != start) {
                        path.push_back(end);    
                        end = pre[end];
                    }
                    path.push_back(start);
                    reverse(all(path));
                    cout << "YES" << endl;
                    cout << path.size() - 1 << endl;
                    for (int i = 1; i < (int)path.size(); i++) {
                        int diff_x = path[i].fi - path[i - 1].fi;
                        int diff_y = path[i].se - path[i - 1].se;
                        for (int k = 0; k < 4; k++) {
                            if (diff_x == dx[k] && diff_y == dy[k]) {
                                cout << moves[k];
                                break;
                            }
                        }
                    }
                    return;
                }
                q.push(next);
            }
        }
    }
    cout << "NO" << endl;
}

signed main() {
    faster();
    int t = 1;
    while (t--) {
        solve();
    }
}