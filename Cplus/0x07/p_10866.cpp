#include <iostream>
#include <deque>

using namespace std;


void push_front(deque<int> &deq) {
    int num;
    cin >> num;
    deq.push_front(num);
}

void push_back(deque<int> &deq) {
    int num;
    cin >> num;
    deq.push_back(num);
}

template <typename T>
void pop_front(T &deq) {
    if (deq.empty()) cout << -1 << '\n';
    else {
        cout << deq.front() << '\n';
        deq.pop_front();
    }
}

template <typename T>
void pop_back(T &deq) {
    if (deq.empty()) cout << -1 << '\n';
    else {
        cout << deq.back() << '\n';
        deq.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    deque<int> deq;
    int num;
    cin >> num;
    while (num--) {
        string str;
        cin >> str;

        if (str == "push_front") push_front(deq);
        else if (str == "push_back") push_back(deq);
        else if (str == "pop_front") pop_front(deq);
        else if (str == "pop_back") pop_back(deq);
        else if (str == "size") cout << deq.size() << '\n';
        else if (str == "empty") cout << (deq.empty() ? 1 : 0) << '\n';
        else if (str == "front") cout << (deq.empty() ? -1 : deq.front()) << '\n';
        else if (str == "back") cout << (deq.empty() ? -1 : deq.back()) << '\n';
    }
}