#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int count;
    cin >> count;

    stack<int> moneyStack;

    for (int i = 0; i < count; i++) {
        int num;
        cin >> num;

        if (num == 0) {
            if (moneyStack.empty())
                continue;
            moneyStack.pop();
        }
        else
            moneyStack.push(num);
    }

    int tot_money = 0;
    while (! moneyStack.empty()){
        tot_money += moneyStack.top();
        moneyStack.pop();
    }    

    cout << tot_money;
}