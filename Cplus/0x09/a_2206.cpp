#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int arr[1000][1000];
int vis[1000][1000][2];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<tuple<int, int, int>> que;

    int N, M;
    cin >> N >> M;

    // map insert
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            arr[i][j] = str[j] - '0';
        }
    }

    que.push({0, 0, 0});
    vis[0][0][0] = 1;
    // int broken = 0;

    while (!que.empty()) {
        auto [ny, nx, b] = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            int y = ny + dy[i];
            int x = nx + dx[i];

            if ((y < 0) || (x < 0) || (y >= N) || (x >= M)) continue;
            if (vis[y][x][b] != 0) continue;
            if ((arr[y][x]) && (!b)) {
                vis[y][x][1] = vis[ny][nx][b] + 1;
                que.push({y, x, 1});
                continue;
            }
            else if ((arr[y][x]) && (b)) {
                continue;
            }

            vis[y][x][b] = vis[ny][nx][b] + 1;
            que.push({y, x, b});
        }
    }

    // report
    int nobreak = vis[N-1][M-1][0];
    int yesbreak = vis[N-1][M-1][1];
    if ((nobreak != 0) && (yesbreak != 0)) {
        if (nobreak < yesbreak)
            cout << nobreak;
        else
            cout << yesbreak;
    }
    else if (nobreak != 0)
        cout << nobreak;
    else if (yesbreak != 0)
        cout << yesbreak;
    else
        cout << -1;
}