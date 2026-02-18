#include <iostream>
#include <queue>

using namespace std;

void push(queue<int> &q) {
    int val;
    cin >> val;
    q.push(val);
}

template <typename T>
void pop(T &que) {
    if (que.empty()) cout << -1 << '\n';
    else {
        cout << que.front() << '\n';
        que.pop();
    }
}

template <typename T>
int check_empty(T &que) {
    return (que.empty() ? 1 : 0);
}

template <typename T>
void front(T &que) {
    if (check_empty(que)) cout << -1 << '\n';
    else cout << que.front() << '\n';
}

template <typename T>
void back(T &que) {
    if (check_empty(que)) cout << -1 << '\n';
    else cout << que.back() << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    queue<int> que;
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;

        if (s == "push") push(que);
        else if (s == "pop") pop(que);
        else if (s == "size") cout << que.size() << '\n';
        else if (s == "empty") cout << check_empty(que) << '\n';
        else if (s == "front") front(que);
        else if (s == "back") back(que);
    }
}