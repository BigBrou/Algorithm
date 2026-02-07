#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt;
    cin >> cnt;

    stack<int> numStack;
    vector<char> pushPop;

    bool no = false;
    int max = 1;
    for (int i = 0; i < cnt; i++) {
        int num;
        cin >> num;

        for (int idx = max; idx <= num; idx++) {
            numStack.push(idx);
            pushPop.push_back('+');
        }

        if (!numStack.empty() && numStack.top() == num) {
            numStack.pop();
            pushPop.push_back('-');
        }
        else {
            no = true;
        }

        if (max <= num) max = num+1;
    }

    if (no) {
        cout << "NO" << '\n';
    }
    else {
        for (char c: pushPop)
            cout << c << '\n';
    }
}