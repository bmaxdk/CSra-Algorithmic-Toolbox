#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  // ----------------------------------------------
  // this myclass is to make my algorithm to sort descending order bigger >smaller
  struct myclass {
  bool operator() (int i, int j) { return (i>j);}
} myobject;



//sort <<<<#here has issu!!!!!
//   struct greater
// {
//     template<class T>
//     bool operator()(T const &a, T const &b) const { return a > b; }
// };
  sort (a.begin(), a.end(), myobject);
  sort (b.begin(), b.end(), myobject);


  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
