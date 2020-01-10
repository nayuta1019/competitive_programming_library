/*
セグメント木(Segment-Tree)

計算量
構築O(N)
クエリO(logN)
*/

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

struct SegmentTree {
  const int INF = numeric_limits<int>::max();
  int n;
  vector<int> node;

  SegmentTree(vector<int> v) {
    int sz = (int)v.size();
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2 * n - 1, INF);
    for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
    for (int i = n - 2; 0 <= i; i--)
      node[i] = min(node[i * 2 + 1], node[i * 2 + 2]);
  }

  SegmentTree(vector<int> v, int x) {
    int sz = (int)v.size();
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2 * n - 1, x);
    for (int i = 0; i < sz; i++) node[i + n - 1] = v[i];
    for (int i = n - 2; 0 <= i; i--)
      node[i] = node[i * 2 + 1] + node[i * 2 + 2];
  }

  // x番目の要素をvalに更新する
  void update(int x, int val) {
    x += (n - 1);
    node[x] = val;
    while (x > 0) {
      x = (x - 1) / 2;
      node[x] = min(node[2 * x + 1], node[2 * x + 2]);
    }
  }

  // 区間[a, b)の要素の最小値を返す. k := 自分がいるノードのインデックス
  int getmin(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;
    if (r <= a || b <= l) return INF;

    if (a <= l && r <= b) return node[k];
    int vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
    int vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
    return min(vl, vr);
  }

  void add(int k, int val) {
    k += (n - 1);
    node[k] += val;
    while (k > 0) {
      k = (k - 1) / 2;
      node[k] = node[2 * k + 1] + node[2 * k + 2];
    }
  }

  int getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) r = n;

    if (b <= l || r <= a) return 0;
    if (a <= l && r <= b) return node[k];

    int vl = getsum(a, b, 2 * k + 1, l, (l + r) / 2);
    int vr = getsum(a, b, 2 * k + 2, (l + r) / 2, r);
    return vl + vr;
  }
};

// AOJ DSL_2_A Range Minimum Query (RMQ)
void RMQ() {
  int n, q, com, x, y;
  cin >> n >> q;
  SegmentTree seg(vector<int>(n, numeric_limits<int>::max()));
  for (int i = 0; i < q; i++) {
    cin >> com >> x >> y;
    if (com)
      cout << seg.getmin(x, y + 1) << endl;
    else
      seg.update(x, y);
  }
}

// AOJ DSL_2_B Range Sum Query (RSQ)
void RSQ() {
  int n, q, com, x, y;
  cin >> n >> q;
  SegmentTree seg(vector<int>(n, 0), 0);
  for (int i = 0; i < q; i++) {
    cin >> com >> x >> y;
    if (com)
      cout << seg.getsum(x - 1, y) << endl;
    else
      seg.add(x - 1, y);
  }
}

int main() {
  // RMQ();
  RSQ();
  return 0;
}
