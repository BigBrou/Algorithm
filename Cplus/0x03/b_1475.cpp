// https://www.acmicpc.net/problem/1475
// 방번호가 백만인거 실화냐

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string N;
    cin >> N; 

    int numbers[10] = {0};
    for (int num : N) {
        numbers[num - '0'] += 1;
    }

    int max = 0;
    for (size_t num = 0; num < sizeof(numbers)/sizeof(numbers[0]); num++) {
        if (num != 6 && num !=9)
            if (numbers[num] > max)
                max = numbers[num];
    }
    int six_nine = int(std::ceil((numbers[6] + numbers[9]) / 2.0f));

    if (six_nine > max)
        max = six_nine;

    cout << max;
}