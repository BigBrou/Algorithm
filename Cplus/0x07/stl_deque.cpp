#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    deque<int> deq;
    deq.push_front(10);
    deq.push_back(20);
    deq.push_front(30);
    cout << deq.size() << '\n';
    if (deq.empty()) cout << "deq empty" << '\n';
    else cout << "deq is not empty" << '\n';

    deq.pop_front();
    deq.pop_back();
    cout << deq.front() << '\n';
    cout << deq.back() << '\n';

    deq.insert(deq.begin()+1, 3);
    for (auto d : deq)
        cout << d << ' ';
    deq.clear();
}
