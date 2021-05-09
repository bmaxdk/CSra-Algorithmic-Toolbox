#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  // write your code here
  int n = values.size();
  std::vector<double> A_array(n);
  double W = capacity;
  std::vector<int> index_v(n);
  std::vector<double> ratio_v(n);

  // build own sort algorithm.
  for(int i = 0; i < n; i++){
    double max_val = double(values.at(i))/double(weights.at(i));
    int count = 0;
    for(int j = 0; j < n; j++){
      if (max_val < double(values.at(j))/double(weights.at(j))){
        // max_val = double(values.at(j))/double(weights.at(j))
        count++;
      }
    }
    // ratio_v.insert(ratio_v.begin() + count, max_val); //i 
    ratio_v[count] = max_val;
  }


  n = ratio_v.size();
  double small_a = 0.0;
  for(int i = 0; i <n; i++){
    // std::cout<<"--------------------Index i = "<< i << std::endl;
    if (W == 0){
      return value;
    }


    for(int j = 0; j < n; j++){
      //here Debug4
      double ratio_cal = double(values.at(j))/weights.at(j); // here add double() is important! otherwise, it will give int not double!
      
      // Debug3 check whether those two actually match

      // here!!!!!-----> problem begins!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      // if (ratio_cal>ratio_v.at(i)) {
      if (ratio_cal==ratio_v.at(i)) { // this is first one that works!

        //here find min(w,W)
        if (weights.at(j) < W){
          small_a = weights.at(j);
        }

        else {
          small_a = W;
        }
        value += small_a * ratio_v.at(i);
        weights.at(j) = small_a;
        A_array.insert(A_array.begin() + i, double(small_a)); //i 
        W -= small_a; 
      }
    }
  }





  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
