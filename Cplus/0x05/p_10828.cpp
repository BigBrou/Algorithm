#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<int> intStack;
    int cnt;
    cin >> cnt;

    for (int i = 0 ; i < cnt; i++) {
        string str;
        cin >> str;

        if (str == "push") {
            int num;
            cin >> num;
            intStack.push(num);
        }
        else if (str == "pop") {
            if (intStack.empty()) {
                cout << "-1\n";
            }
            else {
                cout << intStack.top() << '\n';
                intStack.pop();
            }
        }
        else if (str == "size") {
            cout << intStack.size() << '\n';
        }
        else if (str == "empty") {
            cout << (int)intStack.empty() << '\n';
        }
        else {
            if (intStack.empty()) {
                cout << "-1\n";
            }
            else
                cout << intStack.top() << '\n';
        }        
    }
}