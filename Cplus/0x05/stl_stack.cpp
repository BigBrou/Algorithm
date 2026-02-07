#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.size() << '\n';

    if (s.empty()) cout << "s is empty\n";
    s.pop();
    cout << s.top() << '\n';
    s.pop();
    cout << s.top() << '\n';
    s.pop();
    if (s.empty()) cout << "s is empty\n";
}