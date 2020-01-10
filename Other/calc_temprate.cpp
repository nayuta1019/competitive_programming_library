#include <iostream>

using namespace std;

//関数テンプレートの作り方
template <class T>
T Add(T a, T b) {
  return a + b;
}

int main() {
  cout << Add(1, 2) << endl;
}