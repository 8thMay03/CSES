/*
    Author: kamine
    Created: 2025-02-26 10:51:31
*/
#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
char dir[] = {'R', 'L', 'D', 'U'};

// Dùng string lưu trữ path sẽ bị TLE 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int sx = -1, sy = -1;
    queue<pair<int, int>> monsters;
    vector<vector<int>> monster_time(n, vector<int>(m, INT_MAX));
    vector<vector<int>> parent(n, vector<int>(m, -1)); // Lưu hướng đi
    char grid[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            if (grid[i][j] == 'M') {
                monsters.push({i, j});
                monster_time[i][j] = 0;
            }
        }
    }

    if (sx == 0 || sx == n - 1 || sy == 0 || sy == m - 1) {
        cout << "YES\n0\n";
        return 0;
    }

    // BFS cho quái vật
    while (!monsters.empty()) {
        auto [x, y] = monsters.front();
        monsters.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#' && monster_time[nx][ny] == INT_MAX) {
                monster_time[nx][ny] = monster_time[x][y] + 1;
                monsters.push({nx, ny});
            }
        }
    }

    // BFS cho người chơi
    vector<vector<int>> player_time(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;
    player_time[sx][sy] = 0;
    q.push({sx, sy});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                grid[nx][ny] != '#' && player_time[nx][ny] == INT_MAX &&
                player_time[x][y] + 1 < monster_time[nx][ny]) {
                
                parent[nx][ny] = i; // Lưu hướng đi
                player_time[nx][ny] = player_time[x][y] + 1;
                q.push({nx, ny});

                if (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1) {
                    // Truy vết đường đi
                    cout << "YES\n" << player_time[nx][ny] << '\n';
                    string path;
                    while (nx != sx || ny != sy) {
                        int d = parent[nx][ny];
                        path += dir[d];
                        nx -= dx[d];
                        ny -= dy[d];
                    }
                    reverse(path.begin(), path.end());
                    cout << path << '\n';
                    return 0;
                }
            }
        }
    }
    
    cout << "NO\n";
}
