#include <cstdlib>
# include <iostream>
# include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers){
  int len = numbers.size();
  long long pp = 0;
  long long result = 0;
  for (int i = 0; i < len; i++){
    for(int j = i + 1; j < len; j++){
      pp = (long long)numbers[i] * numbers[j]; //current pair wise product **dong forget long long here!!
      if (pp > result){
        result = pp;
      }

    }
  }
  return result;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
  int len = numbers.size();

  int max_index1 = -1;
  for (int i = 0; i < len; i++){
    if ((max_index1 == -1)||(numbers[i]>numbers[max_index1])){
      max_index1 = i;
    }
  }

  int max_index2 = -1;
  for (int j = 0; j < len; j++){
    if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2]))){
      max_index2 = j;
    }
  }

  // cout << max_index1 << " " << max_index2 << "\n";

  return ((long long) (numbers[max_index1])) * numbers[max_index2];

}

int main() {
/*
  while (true) {
    // int n = rand() % 4 + 2; //add 2 so 2 to 5
    int n = rand() % 100 + 2;
    cout << n << "\n";
    vector<int> a;
    for (int i = 0; i < n; i++){
      a.push_back(rand() % 100000);
    }
    for (int i = 0; i < n; i++){
      cout << a[i] << ' ';
    }
    cout << "\n";
    long long res1 = MaxPairwiseProduct(a);
    long long res2 = MaxPairwiseProductFast(a);
    if (res1 != res2) {
      cout<<"Wrong Answer: " << res1 << ' ' << res2 << "\n";
      break;
    }
    else {
      cout <<"OK\n";
    }
  }*/


  int n;
  cin >> n;
  vector<int> numbers(n);
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  // long long result = MaxPairwiseProduct(numbers);
  long long result = MaxPairwiseProductFast(numbers);

  // long long result = MaxPairwiseProductFast(vector<int>(100000, 0));

  cout << result << "\n\n";





  // cout << numbers[-1] << " <= This is numbers[-1]\n";


}
