#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int count;
    cin >> count;

    vector<int> arr(count+1, 0);
    stack<int> intStack;
    stack<int> tempStack;

    for (int i = 0; i < count; i++) {
        int num;
        cin >> num;

        intStack.push(num);
    }

    while (! intStack.empty()) {
        bool noSignal = false;
        int top = intStack.top();
        int pos = intStack.size();

        intStack.pop();
        if (! intStack.empty()) {
            int front = intStack.top();
            while (front < top) {
                if (! intStack.empty()) {
                    tempStack.push(front);
                    intStack.pop();

                    if (! intStack.empty())
                        front = intStack.top();
                }
                else {
                    noSignal = true;
                    break;
                }
            }
        }
        
        if (noSignal)
            arr[pos] = 0;
        else
            arr[pos] = intStack.size();

        while (! tempStack.empty()) {
            intStack.push(tempStack.top());
            tempStack.pop();
        }
    }

    int arrSize = arr.size();
    for (int num = 1; num <= arrSize-1; num++)
        cout << arr[num] << ' ';
}