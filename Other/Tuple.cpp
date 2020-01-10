#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<std::tuple<std::string, int, size_t>> v;
  for (size_t i = 0; i < N; ++i) {
    char buf[32];
    int p;
    scanf("%s %d", buf, &p);
    v.emplace_back(buf, -p, i + 1);
  }
  std::sort(v.begin(), v.end());

  for (auto const& vi : v) {
    printf("%zu\n", std::get<2>(vi));
  }
}
