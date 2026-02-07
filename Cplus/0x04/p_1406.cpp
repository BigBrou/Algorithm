// https://www.acmicpc.net/problem/1406

#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;

    list<char> charList;
    for (char c : str) charList.push_back(c);

    auto cursor = charList.end();
    
    int cnt;
    cin >> cnt;

    while (cnt--) {
        char op;
        cin >> op;

        if (op == 'L') {
            if (cursor != charList.begin()) 
                cursor--;
        }
        else if (op == 'D') {
            if (cursor != charList.end())
                cursor++;
        }
        else if (op == 'B') {
            if (cursor != charList.begin()) {
                cursor--;
                cursor = charList.erase(cursor);
            }
        }
        else if (op == 'P') {
            char c;
            cin >> c;
            charList.insert(cursor, c);
        }
    }

    for (char c : charList)
        cout << c;

}