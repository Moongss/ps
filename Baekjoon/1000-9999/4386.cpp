#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

#define coord first
#define idx second

struct pqVertex {
  int v1;
  int v2;
  double dist; // min(x, y, z)
};

struct compare {
  bool operator()(const pqVertex &a, const pqVertex &b) {
    return (a.dist > b.dist);
  }
};

int N;
std::vector<std::pair<double, double>> v;
std::priority_queue<pqVertex, std::vector<pqVertex>, compare> pq;

int parent[100000];

int getParent(int x) {
  if (x == parent[x])
    return x;
  else
    return parent[x] = getParent(parent[x]);
}

void setParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);

  if (a < b)
    parent[b] = a;
  else
    parent[a] = b;
}

double solve() {
  double result = 0;

  while (!pq.empty()) {
    pqVertex elem = pq.top();

    if (getParent(elem.v1) != getParent(elem.v2)) {
      setParent(elem.v1, elem.v2);
      result += elem.dist;
    }
    pq.pop();
  }

  return result;
}

int main() {
  std::cin >> N;

  double x, y;
  for (int i = 0; i < N; i++) {
    parent[i] = i;
    std::cin >> x >> y;
    v.push_back({x, y});
  }

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      double xDistance = fabs(v[i].first - v[j].first);
      double yDistance = fabs(v[i].second - v[j].second);
      double distance = sqrt(pow(xDistance, 2.0) + pow(yDistance, 2.0));
      pq.push({i, j, distance});
    }
  }
  std::cout << solve() << std::endl;
  return 0;
}