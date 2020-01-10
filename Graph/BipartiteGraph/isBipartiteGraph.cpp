/*
CodeFestival2017qualB_C
*/
#include <bits/stdc++.h>

using namespace std;

using Graph = vector<vector<int>>;

// 二部グラフ判定
vector<int> color;
bool dfs(const Graph &G, int v, int cur = 0) {
  color[v] = cur;
  for (auto next_v : G[v]) {
    // 隣接頂点がすでに色確定していた場合
    if (color[next_v] != -1) {
      if (color[next_v] == cur) return false;  // 同じ色が隣接したらダメ
      continue;
    }

    // 隣接頂点の色を変えて、再帰的に探索 (一回でも false が返ってきたら false)
    if (!dfs(G, next_v, 1 - cur)) return false;
  }
  return true;
}

int main() {
  long long N, M;
  cin >> N >> M;
  Graph G(N);
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  color.assign(N, -1);
  if (dfs(G, 0)) {
    long long b = 0, w = 0;
    for (int i = 0; i < N; i++) {
      if (color[i])
        b++;
      else
        w++;
    }
    cout << b * w - M << endl;
  } else {
    cout << N * (N - 1) / 2 - M << endl;
  }

  return 0;
}