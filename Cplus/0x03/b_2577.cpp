// https://www.acmicpc.net/problem/2577
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int A, B, C, res;
    cin >> A;
    cin >> B;
    cin >> C;

    vector<int> numbers(10, 0);

    res = A * B * C;
    string str = to_string(res);

    // cout << str << ' ';

    for (char w: str) {
        // cout << w << ' ';
        numbers[int(w)-'0'] += 1; // int 필요 없음음
    }

    for (int x = 0; x < 10; x++) {
        cout << numbers[x] << "\n";
    }
}