#include <iostream>
#include <vector>

using namespace std;

void printVec(const vector<int> &v) {
    for (int x : v) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v1(3, 5);
    printVec(v1);

    v1.push_back(7);
    printVec(v1);

    vector<int> v2(2);
    printVec(v2);

    v2.insert(v2.begin()+1, 3);
    printVec(v2);

    vector<int> v3 = {1, 2, 3, 4};
    v3.erase(v3.begin()+2);
    printVec(v3);

    vector<int> v4;
    v4 = v3;
    v4.pop_back();
    printVec(v4);
    v4.clear();
    printVec(v4);
}