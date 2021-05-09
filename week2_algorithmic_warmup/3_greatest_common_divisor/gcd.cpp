#include <iostream>
using namespace std;
// HW2 p3 gcd
int gcd(int a, int b) {
  int ap;
  if (b == 0) {
      return a;
  }
  ap = a%b;
  return gcd(b, ap);

} 

//   int current_gcd = 1;
//   for (int d = 2; d <= a && d <= b; d++) {
//     if (a % d == 0 && b % d == 0) {
//       if (d > current_gcd) {
//         current_gcd = d;
//       }
//     }
//   }



//   return current_gcd;
// }


int main() {
  int a, b;
  cin >> a >> b;
  cout << gcd(a, b) << endl;
  return 0;
}
