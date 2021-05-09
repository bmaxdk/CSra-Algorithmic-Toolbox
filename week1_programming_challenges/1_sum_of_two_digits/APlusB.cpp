#include <iostream>

using std::cin;
using std::cout;
int plus(int first, int second){
  return first + second;
}

int main() {
  int a = 0;
  int b = 0;
  cin >> a;
  cin >> b;
  cout << plus(a, b)<<"\n";
}
