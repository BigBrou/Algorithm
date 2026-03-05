#include <iostream>
#include <queue>
#include <tuple>

using namespace std;


int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int R, C;
    cin >> R >> C;

    int vis[1000][1000] = {0};
    char arr[1000][1000];

    queue<tuple<int, int, char>> que;
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};

    int fy = 0, fx = 0;
    int jy = 0, jx = 0;
    bool escape =false;
        
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == '#')
                vis[i][j] = -1;
            else if (arr[i][j] == 'J') {
                vis[i][j] = 0;
                jy = i; jx = j;
            }
            else if (arr[i][j] == 'F') {
                vis[i][j] = -2;
                que.push({i, j, 'F'});
            }
        }
    }
    que.push({jy, jx, 'J'});

    while (! que.empty()) {
        auto pnt = que.front(); que.pop();
        int y = get<0>(pnt);
        int x = get<1>(pnt);
        char w = get<2>(pnt);

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if ((ny < 0) || (nx < 0) || (ny >= R) || (nx >= C)) continue;
            if ((vis[ny][nx] <= -1) || (arr[ny][nx] == '#')) continue;
            if (vis[ny][nx] >= 0) continue;

            if (w == 'F') vis[ny][nx] = -2;
            else {
                vis[ny][nx] = vis[y][x] + 1;
                if ((ny == 0) || (nx == 0) || (ny == R-1) || (nx == C-1)) {
                    jy = ny; jx = nx;
                    escape = true;
                    break;
                }
            }
            
            que.push({ny, nx, w});
        }

        if (escape) break;
    }

    // for (int i = 0; i < R; i++) {
    //     for (int j = 0; j < C; j++) {
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    if (escape) cout << ++vis[jy][jx];
    else cout << "IMPOSSIBLE";
}