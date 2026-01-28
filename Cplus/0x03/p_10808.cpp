// https://www.acmicpc.net/problem/10808
#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string input;
    cin >>  input;

    vector<int> alphabet(26, 0);
    int a = 'a';

    for (int w: input) {
        alphabet[w-a] += 1;
    }

    // for (int x = 0; x < 26; x++) {
    //     cout << char(x + a) << ' ';
    // }
    // cout << "\n";

    for (int t: alphabet) {
        cout << t << ' ';
    }
    cout << "\n";
}