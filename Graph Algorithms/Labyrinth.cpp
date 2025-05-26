#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char dir[] = {'D', 'U', 'R', 'L'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int sx, sy;
    char a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                sx = i;
                sy = j;
            }
        }
    }
    queue<pair<int, int>> q;
    int mp[n][m];
    q.emplace(sx, sy);
    a[sx][sy] = '#';
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#') {
                mp[nx][ny] = k;
                if (a[nx][ny] == 'B') {
                    string ans;
                    while (nx != sx || ny != sy) {
                        int it = mp[nx][ny];
                        ans += dir[it];
                        nx -= dx[it];
                        ny -= dy[it];
                    }
                    reverse(ans.begin(), ans.end());
                    cout << "YES" << endl << ans.size() << endl << ans;
                    return 0;
                    return 0;
                }
                q.push({nx, ny});
                a[nx][ny] = '#';
            }
        }
    }
    cout << "NO";
}
