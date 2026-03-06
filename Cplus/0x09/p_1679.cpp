#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;

    queue<int> que;
    que.push(N);

    int arr[100001];
    for (int i = 0; i < 100001; i++)
        arr[i] = -1;
    arr[N] = 0;

    while (!que.empty()) {
        int top = que.front(); que.pop();

        if (top == K) {
            cout << arr[top];
            break;
        }

        int prev = top - 1;
        int fwd = top + 1;
        int telpo = top * 2;
        
        if ((prev >= 0) && (prev <= 100000) && (arr[prev] == -1)) {
            arr[prev] = arr[top] + 1;
            que.push(prev);
        }
        if ((fwd >= 0) && (fwd <= 100000) && (arr[fwd] == -1)) {
            arr[fwd] = arr[top] + 1;
            que.push(fwd);
        }
        if ((telpo >= 0) && (telpo <= 100000) && (arr[telpo] == -1)) {
            arr[telpo] = arr[top] + 1;
            que.push(telpo);
        }
    }
}