//https://www.acmicpc.net/problem/5397

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    int cnt;
    cin >> cnt;

    vector<string> results;
    for (int i = 0; i < cnt; i++) {
        string str;
        cin >> str;

        list<char> charList;
        auto cursor = charList.begin();

        for (char c : str) {
            switch(c) {
                case '<':
                    if (cursor != charList.begin())
                        cursor--;
                    break;
                case '>':
                    if (cursor != charList.end())
                        cursor++;
                    break;
                case '-':
                    if (cursor != charList.begin()) {
                        cursor--;
                        cursor = charList.erase(cursor);
                    }
                    break;
                default:
                    charList.insert(cursor, c);
                    break;
            }
        }

        results.push_back(string(charList.begin(), charList.end()));
    }

    for (const string& s : results)
        cout << s << '\n';
}