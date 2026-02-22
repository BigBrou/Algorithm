#include <iostream>
#include <deque>
#include <vector>
#include <cctype>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        string str;
        int arr_size;
        string arr;
        deque<int> arrDeq;

        cin >> str;
        cin >> arr_size;
        cin >> arr;

        string tempStr = "";
        for (char c : arr) {
            if (c == '[') continue;
            if ((c == ',') || (c == ']')) {
                if (tempStr != "") {
                    arrDeq.push_back(stoi(tempStr));
                    tempStr = "";
                }
            }
            else tempStr += c;
        }

        bool is_front = true;
        bool is_error = false;
        for (char c : str) {
            if (c == 'R') is_front = !is_front;
            else {
                if (arrDeq.empty()) {
                    cout << "error" << '\n';
                    is_error = true;
                    break;
                }

                if (is_front)
                    arrDeq.pop_front();
                else
                    arrDeq.pop_back();
            }
        }

        if (is_error) {
            is_error = false;
            continue;
        }
        
        // print
        cout << "[";
        while (!arrDeq.empty()) {
            if (is_front) {
                cout << arrDeq.front();
                arrDeq.pop_front();
            }
            else {   
                cout << arrDeq.back();
                arrDeq.pop_back();
            }

            if (!arrDeq.empty())
                cout << ',';
        }
        cout << "]" << '\n';
    }
}