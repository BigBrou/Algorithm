#include <iostream>

int topDownFibonacci(int arr[], int n) {
    if (n <= 0)
        return 0;
    else if (n == 1) {
        arr[n] = 1;
        return arr[n];
    }
    else {
        if (arr[n] != 0)
            return arr[n];

        arr[n] = topDownFibonacci(arr, n-1) + topDownFibonacci(arr, n-2);
        return arr[n];
    }
}

int bottomUpFibonacci(int arr[], int n) {
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i-2] + arr[i-1];
    }

    return arr[n];
}



int main() {
    int n = 10;
    int result = 0;

    int arr[n];
    std::fill(arr, arr+n, 0);

    //result = topDownFibonacci(arr, n-1);
    result = bottomUpFibonacci(arr, n-1);
    std::cout << result;


    return 0;
}

