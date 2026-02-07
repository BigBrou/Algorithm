#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int count;
    cin >> count;

    vector<int> check_arr(1000001, 0);
    vector<int> arr(count, 0);
    for (int i = 0; i < count; i++) {
        int temp;
        cin >> temp;
        arr[i] = temp;
        check_arr[temp]++;
    }

    int x;
    cin >> x;

    int counter = 0;
    for (int i = 0; i < arr.size(); i++) {
        int y = x - arr[i];
        if (y < 0 || y > 1000000) continue;

        if (check_arr[y] > 0 && y != arr[i]) {
            counter += 1;
            check_arr[arr[i]] = 0;
        }
    }

    cout << counter;
}