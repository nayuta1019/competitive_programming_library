#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/*
template <typename T>
struct MultidimensionalArray {
  int N, M;
  Vec<T> arr;
  MultidimensionalArray() { MultidimensionalArray(1, 1); }
  MultidimensionalArray(int n, int m) {  // 要素数nのm次元配列を作る
    init(n, m);
  }

  void init(int n, int m) {
    N = n, M = m;
    n = pow(n, m);
    arr.resize(n);
  }

  // 代入する値, インデックス配列
  void set(T element, const Vec<int> n) {
    int sz = n.size();
    int index = 0;
    for (int i = sz - 1; 0 <= i; i--) {
      int cur = n[i];
      index += pow(N, i) * cur;
    }
    arr[index] = element;
  }

  // 取得する値のインデックス配列
  T get(const Vec<int> n) {
    int sz = n.size();
    int index = 0;
    for (int i = sz - 1; 0 <= i; i--) {
      int cur = n[i];
      index += pow(N, i) * cur;
    }
    return arr[index];
  }
};
*/

template <typename T>
struct MultidimensionalArray {
  int N, M;
  vector<T> arr;
  MultidimensionalArray() { MultidimensionalArray(0, 1); }
  MultidimensionalArray(int n, int m) {  // 要素数nのm次元配列を作る
    init(n, m);
  }

  void init(int n, int m) {
    N = n, M = m;
    n = pow(n, m);
    arr.resize(n);
  }

  void set(T element, int first, ...) {
    int index = first;
    va_list args;
    va_start(args, first);
    for (int i = 1; i < M; i++) {
      int cur = va_arg(args, int);
      index += pow(N, i) * cur;
    }
    va_end(args);
    arr[index] = element;
  }

  T get(int first, ...) {
    int index = first;
    va_list args;
    va_start(args, first);
    for (int i = 1; i < M; i++) {
      int cur = va_arg(args, int);
      index += pow(N, i) * cur;
    }
    va_end(args);
    return arr[index];
  }

  // 代入する値, インデックス配列
  void set(T element, const vector<int> n) {
    int sz = n.size();
    int index = 0;
    for (int i = sz; 0 <= i; i--) {
      int cur = n[i];
      index += pow(N, i) * cur;
    }
    arr[index] = element;
  }

  // 取得するインデックス配列
  T get(const vector<int> n) {
    int sz = n.size();
    int index = 0;
    for (int i = sz; 0 <= i; i--) {
      int cur = n[i];
      index += pow(N, i) * cur;
    }
    return arr[index];
  }
};
const int Nmax = 5;
MultidimensionalArray<int> arr2;
int arr1[Nmax][Nmax][Nmax];

void print3D(int arr[Nmax][Nmax][Nmax]) {
  for (int i = 0; i < Nmax; i++) {
    cout << "------- c" << i << " -------\n";
    for (int j = 0; j < Nmax; j++) {
      for (int k = 0; k < Nmax; k++) {
        cout << arr[i][j][k] << " ";
      }
      cout << endl;
    }
  }
}
void print3D(int arr[Nmax * Nmax * Nmax]) {
  for (int i = 0; i < Nmax; i++) {
    cout << "------- c" << i << " -------\n";
    for (int j = 0; j < Nmax; j++) {
      for (int k = 0; k < Nmax; k++) {
        cout << arr[k + Nmax * j + Nmax * Nmax * i] << " ";
      }
      cout << endl;
    }
  }
}

void solve2() {
  arr2.init(5, 2);
  for (int i = 0; i < Nmax; i++) {
    for (int j = 0; j < Nmax; j++) {
      vector<int> index;
      index.push_back(i);
      index.push_back(j);

      arr2.set(j + i * Nmax, index);
    }
  }

  for (int i = 0; i < Nmax; i++) {
    for (int j = 0; j < Nmax; j++) {
      vector<int> index;
      index.push_back(i);
      index.push_back(j);

      cout << arr2.get(index) << " ";
    }
    cout << endl;
  }

  vector<int> index;
  index.push_back(0);  // y
  index.push_back(1);  // x
  cout << arr2.get(index) << endl;
}

void solve() {
  arr2.init(5, 4);
  for (int i = 0; i < Nmax; i++) {
    for (int j = 0; j < Nmax; j++) {
      for (int k = 0; k < Nmax; k++) {
        for (int l = 0; l < Nmax; l++) {
          vector<int> index;
          index.push_back(i);
          index.push_back(j);
          index.push_back(k);
          index.push_back(l);
          arr2.set(l + Nmax * k + Nmax * Nmax * j + Nmax * Nmax * Nmax * i,
                   index);
        }
      }
    }
  }

  for (int i = 0; i < Nmax; i++) {
    cout << "------- i" << i << " -------\n";
    for (int j = 0; j < Nmax; j++) {
      cout << "------- j" << j << " -------\n";
      for (int k = 0; k < Nmax; k++) {
        for (int l = 0; l < Nmax; l++) {
          vector<int> index;
          index.push_back(i);
          index.push_back(j);
          index.push_back(k);
          index.push_back(l);
          cout << arr2.get(index) << " ";
        }
        cout << endl;
      }
    }
  }
}

int main() {
  solve2();

  return 0;
}