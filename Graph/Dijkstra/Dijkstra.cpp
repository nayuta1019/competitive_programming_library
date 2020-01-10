/*
単一始点最短経路(Dijkstra)
計算量 : O(ElogV)

ABC035 D
NIKKEI2019-2 D
ARC026 C
*/
#include <iostream>
#include <limits>
#include <queue>
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
template <typename T>
using Graph = vector<Edges<T>>;

template <typename T>
vector<T> dijkstra(Graph<T> &G, int s) {
  const auto INF = numeric_limits<T>::max();  // Be careful not to overflow
  vector<T> dist(G.size(), INF);
  using Pli = pair<T, int>;
  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  dist[s] = 0;
  que.emplace(dist[s], s);  // cost, from
  while (!que.empty()) {
    Pli p = que.top();
    que.pop();
    T cost = p.first;
    int cur = p.second;
    if (dist[cur] < cost) continue;
    for (auto e : G[cur]) {
      auto next_cost = dist[cur] + e.cost;
      if (dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}

int main() {
  int n, m, r;
  cin >> n >> m >> r;
  Graph<int> G(n);

  int from, to, cost;
  for (int i = 0; i < m; i++) {
    cin >> from >> to >> cost;
    G[from].emplace_back(to, cost);
  }

  auto dist = dijkstra(G, r);

  for (auto d : dist) {
    if (d == numeric_limits<int>::max()) {
      cout << "INF\n";
    } else {
      cout << d << endl;
    }
  }

  return 0;
}