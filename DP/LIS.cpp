/*
数列A = a_0, a_1, a_2, ..., a_{n-1}の増加部分列とは
0 <= i_0 < i_1 < ... < i_k < n かつ
a_{i_0} < a_{i_1} < ... < a_{i_k}を満たす部分列 a_{i_0}, a_{i_1}, a_{i_k}
です.最長増加部分列はその中で最もkの大きいものです.
計算量 : O(NlogN)
*/
#include <iostream>
#include <vector>

using namespace std;

/* 最長増加部分列 */
template <typename T>
size_t LIS(const vector<T> &A) {
  size_t n = A.size();
  vector<T> L;
  L.push_back(A[0]);
  size_t length = 1;
  for (int i = 1; i < n; i++) {
    if (L[length - 1] < A[i]) {
      L.push_back(A[i]);
      length++;
    } else {
      *lower_bound(L.begin(), L.end(), A[i]) = A[i];
    }
  }

  return length;
}

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++) cin >> c[i];

  cout << LIS(c) << endl;

  return 0;
}