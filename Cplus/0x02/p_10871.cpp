// https://www.acmicpc.net/problem/10871


#include <iostream>

using namespace std;


int main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int N, X;
    std::cin >> N >> X;

    int arr[N];
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        if (arr[i] < X)
            std::cout << arr[i] << " ";
    }
}