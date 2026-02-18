#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void) {
    int tot, cnt;
    cin >> tot >> cnt;

    vector<int> arr(cnt, 3);
    for (int i = 0; i < cnt; i++) {
        int num;
        cin >> num;
        arr[i] = num;
    }

    deque<int> deq;
    for (int i = 1; i <= tot; i++)
        deq.push_back(i);

    int move = 0;
    for (int num : arr) {
        auto it = find(deq.begin(), deq.end(), num);
        int f_gap = distance(deq.begin(), it);
        int r_gap = deq.size() - f_gap;

        while (num != deq.front()) {
            if (f_gap < r_gap) {
                int front = deq.front();
                deq.pop_front();
                deq.push_back(front);
            }
            else {
                int back = deq.back();
                deq.pop_back();
                deq.push_front(back);
            }
            move++;
        }
        deq.pop_front();
    }
    cout << move << '\n';
}