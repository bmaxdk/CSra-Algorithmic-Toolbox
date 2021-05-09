#include <iostream>
#include <chrono>

using namespace std;

// // HW2 p1 this is too slow
// int fibonacci_old(int n) {
//     if (n <= 1)
//         return n;

//     return fibonacci_old(n - 1) + fibonacci_old(n - 2);
// }

// // HW2 p1
// int fibonacci(int n) {
//     int arrayF[n];
//     arrayF[0] = 0;
//     arrayF[1] = 1;
//     for (int i = 2; i < n; i++){ //<<This should be <=
//         arrayF[i] = arrayF[i-1]+arrayF[i-2];
//     }
//     return arrayF[n];

// }


// HW2 p1
int fibonacci(int n) {
    int arrayF[n];
    arrayF[0] = 0;
    arrayF[1] = 1;
    for (int i = 2; i <= n; i++){
        arrayF[i] = arrayF[i-1]+arrayF[i-2];
        // cout << arrayF[i] <<endl;
    }
    return arrayF[n];

}


int main() {
    int n;
    cin >> n;
    // auto t1 = std::chrono::high_resolution_clock::now();
    cout << fibonacci(n) << '\n';
    // auto t2 = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
    // cout << duration<<"\n";

    return 0;
}

