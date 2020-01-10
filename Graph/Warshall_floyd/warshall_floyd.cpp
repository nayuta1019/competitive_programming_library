/**
ワーシャルフロイド法は, グラフの全ての頂点の間の最短路を見つけるアルゴリズム.
計算量 : O(V^3).
ワーシャルフロイド法は負の辺に対応できる.
負の閉路があると, d[i][i]が負となる(d[i][i]は負閉路がなければ0になっているはず).
**/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;
vector<vector<int>> dist;

void warshall_floyd(int n) {       // nは頂点数
  for (int k = 0; k < n; k++)      // 経由する頂点
    for (int i = 0; i < n; i++)    // 開始頂点
      for (int j = 0; j < n; j++)  // 終端
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
  int n, m;
  cin >> n >> m;
  dist = vector<vector<int>>(n, vector<int>(n, INF));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dist[i][j] = INF;
    }
  }
  for (int i = 0; i < n; i++) dist[i][i] = 0;

  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    from--, to--;  // 0-index
    dist[from][to] = cost;
  }

  warshall_floyd(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && dist[i][j] != INF)
        cout << i + 1 << "から" << j + 1 << "へのコスト: " << dist[i][j]
             << endl;
    }
  }

  return 0;
}