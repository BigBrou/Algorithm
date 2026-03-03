#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define Y first
#define X second


bool checkNonZero(int arr[][1000], int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                return false;
                break;
            }
        }
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[1000][1000] = {0};
    int vis[1000][1000] = {0};

    queue<pair<int, int>> que;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    int max = 0;

    int M, N;
    cin >> M >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    if (checkNonZero(arr, N, M)) cout << 0;
    else {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (arr[i][j] == 1) {
                    vis[i][j] = 1;
                    que.push({i, j});
                }
                else if (arr[i][j] == -1) {
                    vis[i][j] = -1;
                }
            }
        }
        
        while (!que.empty()) {
            auto point = que.front(); que.pop();

            for (int p = 0; p < 4; p++) {
                int ny = point.Y + dy[p];
                int nx = point.X + dx[p];

                if ((ny < 0) || (nx < 0) || (ny >= N) || (nx >= M)) continue;
                if ((vis[ny][nx] > 0) || (arr[ny][nx] == -1)) continue;

                vis[ny][nx] = vis[point.Y][point.X] + 1;
                if (max < vis[ny][nx]) max = vis[ny][nx];
                que.push({ny, nx});
            }
        }

        if (checkNonZero(vis, N, M)) cout << --max;
        else cout << -1;
    }
}