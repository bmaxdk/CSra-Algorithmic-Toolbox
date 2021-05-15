#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;


void merge(vector<int>& v, int p, int q, int r) {
  int size1 = q-p+1;
  int size2 = r-q;
  vector<long long int> L(size1);
  vector<long long int> R(size2);
  for(int i = 0; i < size1; i++) {
    L[i] = v[p+i];
  }
  for(int j = 0; j < size2; j++) {
    R[j]=v[q+j+1];
  }

  int i=0,j=0;
  int k;
  for(k = p; k <= r && i < size1 && j < size2; k++) {
    if(L[i] <= R[j]) {
      v[k] = L[i];
      i++;
    } else {
      v[k] = R[j];
      j++;
    }
  }
  for(i = i; i < size1; ++i) {
    v[k] = L[i];
    k++;
  }

  for(j = j; j < size2; j++) {
    v[k] = R[j];
    k++;
  }
}

void merge_sort(vector<int>& v, int p, int r) {
  if(p < r) {
    int q = (p+r)/2;
    merge_sort(v, p, q);
    merge_sort(v, q+1, r);
    merge(v, p, q, r);
    // cout<< "a";
  }
}


int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  merge_sort(a, left, right);  
  int count = 1;
  int majority = (a.size())/2+1;
//   std::cout << majority;
  int current_a = 0;
  int a_prev = 0;

//   std::cout << "\na.size() = "<<a.size() << std::endl;
  for (int i=1; i<=a.size(); i++) {
    // cout << a[i] << " ";
    current_a = a[i];
    // cout << a[i] << " ";
    //build comparison here /////////<=== 
    // recommend add search algorithm?? maybe?
    //   std::vector<int> hold_val(a.size());
    // current_val = a[i];
    // std::cout << "\ncurrent_a = "<<current_a << std::endl;
    // std::cout << "\na_prev = "<<a_prev << std::endl;
    if (current_a == a_prev) {
      count++;
    //   std::cout << "\ncount = "<<count << std::endl;
      if (count == majority){
        //   std::cout << "\ncount = "<<count << std::endl;
        //   std::cout << "\nmajority = "<<majority << std::endl;   
          return 1;
      }
    } else {
      count = 1;
      a_prev = current_a;
    }
  }
  cout<< endl;

  return -1;
}



int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
