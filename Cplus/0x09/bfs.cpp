#include <iostream>
#include <utility>
#include <queue>

using namespace std;

#define X first
#define Y second

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int board[500][500] = {
        {1,1,1,0,1,0,0,0,0,0},
        {1,0,0,0,1,0,0,0,0,0},
        {1,1,1,0,1,0,0,0,0,0},
        {1,1,0,0,1,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0} 
    };
    int vis[500][500] = {0};
    int n = 7, m = 10;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    queue<pair<int, int>> que;
    vis[0][0] = 1;
    que.push({0, 0});
    while (! que.empty()) {
        auto point = que.front();
        cout << '(' << point.X << ',' << point.Y << ')' << '\n';
        vis[point.X][point.Y] = 1;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int nx = point.X + dx[i];
            int ny = point.Y + dy[i];
            if ((nx < 0) || (nx >= n) || (ny < 0) || (ny >= m)) continue;
            if ((vis[nx][ny]) || (board[nx][ny] == 0)) continue;
            que.push({nx, ny});
        }
    }
}