#include <iostream>

template <typename T, typename U, typename V>
T AddThreeNumbers(T a, U b, V c);

int main() {
  std::cout << AddThreeNumbers(6, 9, 7) << std::endl;
  std::cout << AddThreeNumbers(6.7, 9.6, 0.0);
}

template <typename T, typename U, typename V>
T AddThreeNumbers(T a, U b, V c) {
  return a + b + c;
}
