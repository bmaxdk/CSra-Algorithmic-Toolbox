#include <iostream>
#include <cassert>
using namespace std;

// // for HW2_2 _this is too slow
// int fibonacci_fast(int n) {
//     if (n <= 1)
//         return n;

//     int ans = (fibonacci_fast(n-1) + fibonacci_fast(n-2))%10;

//     return ans;
// }

// for HW2_2
int fibonacci_fast(int n) {
    int arrayF[n];
    arrayF[0] = 0;
    arrayF[1] = 1;
    for (int i = 2; i<=n; i++){
        arrayF[i] = (arrayF[i-1] + arrayF[i-2])%10;
    }

    return arrayF[n];
}


int main() {
    int n = 0;
    cin >> n;
    cout << fibonacci_fast(n) << '\n';
    return 0;
}
