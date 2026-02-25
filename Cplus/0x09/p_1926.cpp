// 고정된 문자열 말고 arr[n][m] 넣으면 쓰레기값이 주입됨 주의

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second 

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int arr[501][501] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            arr[i][j] = num;
        }
    }

    int vis[501][501] = {0};
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<pair<int, int>> que;
    int tot = 0;
    int max = 0;

    for (int idx = 0; idx < n; idx++) {
        for (int jdx = 0; jdx < m; jdx++) {
            if ((vis[idx][jdx]) || (arr[idx][jdx] == 0)) continue;

            vis[idx][jdx] = 1;
            que.push({idx, jdx});
            int cnt = 1;
            tot++;
            
            while (!que.empty()) {
                auto point = que.front();
                que.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = point.X + dx[i];
                    int ny = point.Y + dy[i];

                    if ((nx < 0) || (ny < 0) || (nx >= n) || (ny >= m)) continue;
                    if ((vis[nx][ny]) || (arr[nx][ny]) == 0) continue;
                    
                    vis[nx][ny] = 1;
                    que.push({nx, ny});
                    cnt++;
                }
            }
            if (cnt > max) max = cnt;
        }
    }
    
    cout << tot << '\n' << max <<'\n';
}