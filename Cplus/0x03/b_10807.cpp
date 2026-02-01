// https://www.acmicpc.net/problem/10807

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt;
    cin >> cnt;

    vector<int> arr_minus_cnt(101, 0);
    vector<int> arr_plus_cnt(101, 0);
    for (int i = 0; i < cnt; i++) {
        int num;
        cin >> num;

        if (num < 0)
            arr_minus_cnt[abs(num)] += 1;
        else
            arr_plus_cnt[num] += 1;
    }

    int find_num;
    cin >> find_num;

    if (find_num < 0)
        cout << arr_minus_cnt[abs(find_num)];
    else
        cout << arr_plus_cnt[find_num];
}
