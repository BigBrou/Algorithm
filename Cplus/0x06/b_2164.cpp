#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    cin >> num;
    
    queue<int> que;
    for (int i = 1; i <= num; i++)
        que.push(i);
    
        num--;
    while (num--) {
        que.pop();
        
        int front = que.front();
        que.pop();
        que.push(front);
    }
    cout << que.front();
}