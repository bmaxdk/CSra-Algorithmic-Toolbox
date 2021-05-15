#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;


void merge(vector<int>& v, int p, int q, int r) {
  int size1 = q-p+1;
  int size2 = r-q;
  vector<long long> L(size1);
  vector<long long> R(size2);
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
  }
}


int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  std::cout << "\n" << std::endl;
  merge_sort(a, left, right);  
  int count = 1;
  int majority = (a.size())/2+1;
  int current_a = 0;
  int a_prev = 0;

  for (int i=0; i<=a.size(); i++) {
    current_a = a[i];

    if (current_a == a_prev) {
      count++;

      if (count == majority){   
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
