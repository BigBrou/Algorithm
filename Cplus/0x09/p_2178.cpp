#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

#define X first
#define Y second

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int arr[100][100] = {0};
    int vis[100][100] = {0};
    queue<pair<int, int>> que;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            arr[i][j] = str[j] - '0';
    }
    
    vis[0][0] = 1;
    que.push({0, 0});
    
    while(!que.empty()) {
        auto point = que.front(); que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = point.X + dx[i];
            int ny = point.Y + dy[i];

            if ((nx < 0) || (ny < 0) || (nx >= n) || (ny >= m)) continue;
            if ((vis[nx][ny]) || (arr[nx][ny] == 0)) continue;

            vis[nx][ny] = vis[point.X][point.Y] + 1;
            que.push({nx, ny});
        }
    }
    cout << vis[n-1][m-1];
}