#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    queue<int> que;
    que.push(10);
    que.push(20);
    que.push(30);
    cout << que.size() << "\n";
    if (que.empty()) cout << "queue empty" << "\n";
    else cout << "queue is not empty" << "\n";
    cout << que.front() << " front\n";
    cout << que.back() << "\n";
    que.push(40);
    que.pop();
}