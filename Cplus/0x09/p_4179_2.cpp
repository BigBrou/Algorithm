// Failure (helped by gpt)

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

#define Y first
#define X second
#define INF 5

int fire[1000][1000];
int vis[1000][1000];
char pos[1000][1000];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int R, C;
    cin >> R >> C;

    int fy = 0; int fx = 0;
    int jy = 0; int jx = 0;

    queue<pair<int, int>> que;

    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            fire[i][j] = -1;
            vis[i][j] = -1;
        }
    }

    for (int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> pos[i][j];
            if (pos[i][j] == '#') {
                fire[i][j] = -INF;
                vis[i][j] = -INF;
            }
            else if (pos[i][j] == 'F') {
                fire[i][j] = 0;
                vis[i][j] = -INF;
                que.push({i, j});
            }
            else if (pos[i][j] == 'J') {
                vis[i][j] = 0;
                jy = i; jx = j;
            }
        }
    }

    // fire
    while (!que.empty()) {
        auto pnt = que.front(); que.pop();

        for (int i = 0; i < 4; i++) {
            int ny = pnt.Y + dy[i];
            int nx = pnt.X + dx[i];

            if ((ny < 0) || (nx < 0) || (ny >= R) || (nx >= C)) continue;
            if ((fire[ny][nx] >= 0) || (pos[ny][nx] == '#')) continue;

            fire[ny][nx] = fire[pnt.Y][pnt.X] + 1;
            que.push({ny, nx});
        }
    }

    while (!que.empty())
        que.pop();

    // for debug
    // for (int i = 0; i < R; i++) {
    //     for(int j = 0; j < C; j++) {
    //         cout << fire[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // person
    que.push({jy, jx});
    while (!que.empty()) {
        auto pnt = que.front(); que.pop();

        for (int i = 0; i < 4; i++) {
            int ny = pnt.Y + dy[i];
            int nx = pnt.X + dx[i];

            if ((ny < 0) || (nx < 0) || (ny >= R) || (nx >= C)) {
                cout << vis[pnt.Y][pnt.X] + 1;
                return 0;
            }

            if ((vis[ny][nx] >= 0) || (pos[ny][nx] == '#')) continue;
            if (fire[ny][nx] != -1 && fire[ny][nx] <= vis[pnt.Y][pnt.X] + 1) continue;

            vis[ny][nx] = vis[pnt.Y][pnt.X] + 1;
            que.push({ny, nx});
        }
    }

    // for debug
    // for (int i = 0; i < R; i++) {
    //     for(int j = 0; j < C; j++) {
    //         cout << vis[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << "IMPOSSIBLE";
}