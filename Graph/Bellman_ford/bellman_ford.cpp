/*
単一始点最短経路(Bellman-Ford)
計算量 : 辺の数をE, 頂点数をVとすると, O(EV).
負の辺があっても正しく動作し, 負の閉路を検出することができる.
*/
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

template <typename T>
struct edge {
  int from, to;
  T cost;
  edge(int t, T c) { to = t, cost = c; }
  edge(int f, int t, T c) { from = f, to = t, cost = c; }
};

template <typename T>
using Edges = vector<edge<T>>;
using Graph = vector<Edges<T>>;

template <typename T>
vector<T> bellman_ford(Edges<T> &edges, T n, T s) {  // nは頂点数, sは開始頂点
  const auto INF = numeric_limits<T>::max();  // Be careful not to overflow
  vector<T> dist(n, INF);
  dist[s] = 0;
  for (int i = 0; i < n; i++) {
    for (auto e : edges) {
      if (dist[e.from] == INF) continue;
      if (dist[e.to] > dist[e.from] + e.cost) {
        dist[e.to] = dist[e.from] + e.cost;
        if (i == n - 1) {  // n回目に更新があれば負の閉路が存在する
          return vector<T>();
        }
      }
    }
  }

  return dist;
}

int main() {
  int n, m, r;
  cin >> n >> m >> r;
  Edges<int> edges;
  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    edges.emplace_back(from, to, cost);
  }

  auto dist = bellman_ford(edges, n, r);

  if (dist.empty()) {
    cout << "NEGATIVE CYCLE\n";
  }

  for (auto d : dist) {
    if (d == numeric_limits<int>::max())
      cout << "INF\n";
    else
      cout << d << endl;
  }

  return 0;
}