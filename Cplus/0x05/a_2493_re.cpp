#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main(void) {
    int cnt;
    cin >> cnt;

    stack<pair<int, int>> stk;
    int arr[cnt+1]={0};

    for (int i = 1; i <= cnt; i++) {
        int num;
        cin >> num;

        if (i == 1) arr[i] = 0;

        while (!stk.empty()) {
            auto topNum = stk.top();
            if (topNum.first > num) {
                arr[i] = topNum.second;
                break;
            }
            else {
                stk.pop();
            }
        }

        stk.push({num, i});
    }
    
    for (int idx = 1; idx <= cnt; idx++)
        cout << arr[idx] << ' ';
}