/**
基本
> 1 点に足す・prefix の和を求める
> bit[x] に右端が x で長さ x & -x の区間の和をもたせる
応用
> 差分・部分和に対する問題を考えてみる
> 多次元は多重ループ
> 高速に二分探索できる

計算量
N個の区間の和を管理する
> O(N)メモリ
変数の値の更新
> O(logN)時間
>> 高々 (logN+1) 個の区間に足す
prefix の和の計算
> O(logN) 時間
>> 高々 (logN + 1) 個の区間の和
**/
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
struct BinaryIndexedTree {
  vector<T> data;

  BinaryIndexedTree(int sz) { data.assign(++sz, 0); }

  T sum(int k) {
    T ret = 0;
    for (++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for (++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

// AOJ DSL_2_B Range Sum Query
int main() {
  int N, Q;
  cin >> N >> Q;
  BinaryIndexedTree<int> bit(N);
  while (Q--) {
    int T, X, Y;
    scanf("%d %d %d", &T, &X, &Y);
    if (T == 0)
      bit.add(X - 1, Y);
    else
      printf("%d\n", bit.sum(Y - 1) - bit.sum(X - 2));
  }
}