#include <iostream>
using namespace std;

void print(int n, int A[]) {
  for (int i = 0; i < n; i++) cout << A[i] << " ";
  cout << endl;
}

//挿入ソート O(n^2) 安定ソート
void insertionSort(int A[], int N) {
  for (int i = 1; i < N; i++) {
    int v = A[i];
    int j = i - 1;

    while (0 <= j && v < A[j]) {
      A[j + 1] = A[j];
      j--;
      A[j + 1] = v;
    }
    // print(N, A);
  }
}

//バブルソート O(n^2) 安定ソート
int bubbleSort(int A[], int N) {
  int sw = 0;  // swapした回数

  bool flag = true;
  for (int i = 0; flag; i++) {
    flag = false;
    for (int j = N - 1; i < j; j--) {
      if (A[j] < A[j - 1]) {
        int tmp = A[j];
        A[j] = A[j - 1];
        A[j - 1] = tmp;
        // swap(A[j], A[j-1]);でもOK
        flag = true;
        sw++;
      }
    }
  }
  return sw;
}
