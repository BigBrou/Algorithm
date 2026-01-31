#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int count;
    cin >> count;

    vector<int> check_arr(1000000, 0);
    vector<int> arr(count, 0);
    for (int i = 0; i < count; i++) {
        int temp;
        cin >> temp;
        arr[i] = temp;
        check_arr[temp] += 1;
    }

    int x;
    cin >> x;

    int counter = 0;
    for (int i = 0; i < arr.size(); i++) {
        int remain = x - arr[i];
        if (remain > 0 && check_arr[remain] > 0) {
            counter += 1;
        }

    }

    cout << counter / 2;
}