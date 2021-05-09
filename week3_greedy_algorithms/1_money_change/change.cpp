#include <iostream>

int get_change(int m) {
  //write your code here
  int n = 0;
  while(m != 0){
    if(m/10 != 0){
      int r = m/10;
      n += r;
      m -= 10*r;
      // std::cout << "at 10 m =" << m;
    }
    if(m/5 != 0){
      int r = m/5;
      n += r;
      m -= 5*r;
      //std::cout << "at 5 m =" << m;

    }
    if(m/1 != 0){
      int r = m;
      n += r;
      m -= r;
      // std::cout << "at 1 m =" << m;

    }
  }


  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
