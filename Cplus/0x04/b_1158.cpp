#include <iostream>
#include <list>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num, gap;
    cin >> num >> gap;

    list<int> numList;
    list<int> eraseList;
    for (int i = 1; i <= num; i++) numList.push_back(i);

    auto cursor = numList.begin();

    while (! numList.empty()) {
        if (cursor == numList.end())
            cursor = numList.begin();

        for (int idx = 0; idx < gap - 1; idx++) {
            cursor++;
            if (cursor == numList.end())
                cursor = numList.begin();
        }

        eraseList.push_back(*cursor);
        cursor = numList.erase(cursor);
    }

    cout << '<';
    for (auto it = eraseList.begin(); it != eraseList.end(); it++) {
        if (it != eraseList.begin())
            cout << ", ";
        cout << *it;
    }

    cout << '>';
}