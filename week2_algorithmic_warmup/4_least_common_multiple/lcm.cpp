#include <iostream>
using namespace std;
// lcm(a,b) = (axb) / GCD(a,b)
// long long lcm(int a, int b) {
//   for (long l = 1; l <= (long long) a * b; ++l)
//     if (l % a == 0 && l % b == 0)
//       return l;

//   return (long long) a * b;
// }

int gcd(int a, int b) {
  int ap;
  if (b == 0) {
      return a;
  }
  ap = a%b;
  return gcd(b, ap);

} 

long long lcm(int a, int b) {//long long here very important
    long long ans; //long long here very important
    // cout << gcd(a,b) <<endl;
    long long mult = (long long) a*b;
    ans = mult/gcd(a,b); //here long long is very important!!
    // cout << mult<<endl;
    // cout << ans<<endl;
    return ans;
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << lcm(a, b) << endl;
  return 0;
}



// #include <iostream>
// using namespace std;
// // lcm(a,b) = (axb) / GCD(a,b)
// // long long lcm(int a, int b) {
// //   for (long l = 1; l <= (long long) a * b; ++l)
// //     if (l % a == 0 && l % b == 0)
// //       return l;

// //   return (long long) a * b;
// // }

// int gcd(int a, int b) {
//   int ap;
//   if (b == 0) {
//       return a;
//   }
//   ap = a%b;
//   return gcd(b, ap);

// } 

// // int lcm(int a, int b) {
// //     int ans;
// //     // cout << gcd(a,b) <<endl;
// //     long long mult = (long long) a*b;
// //     ans = mult/gcd(a,b); //here long long is very important!!
// //     cout << mult<<endl;
// //     cout << mult/gcd(a,b)<<endl;
// //     return ans;
// // }


// int lcm_top(int a, int b) {
//     int mult;
//     // cout << gcd(a,b) <<endl;
//     mult = (long long) a*b;

//     return mult;
// }

// int main() {
//   int a, b;
//   cin >> a >> b;
//   int lcm = lcm_top(a,b)/gcd(a,b);
//   cout << lcm_top << endl;
//   return 0;
// }
