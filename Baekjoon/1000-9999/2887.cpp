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
  int dist; // min(x, y, z)
};

struct compare {
  bool operator()(const pqVertex &a, const pqVertex &b) {
    return (a.dist > b.dist);
  }
};

int N;
std::vector<std::pair<int, int>> xVec, yVec, zVec;
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

int solve() {
  int result = 0;
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

  int x, y, z;
  for (int i = 0; i < N; i++) {
    parent[i] = i;
    std::cin >> x >> y >> z;
    xVec.push_back({x, i});
    yVec.push_back({y, i});
    zVec.push_back({z, i});
  }

  // sort by first elem(coord)
  std::sort(xVec.begin(), xVec.end()); // 1 - 2, 2 - 3, 3 - 4 : min (N)
  std::sort(yVec.begin(), yVec.end()); // same
  std::sort(zVec.begin(), zVec.end()); // same

  // for (int i = 0; i < N; i++) {
  //   std::cout << xVec[i].coord << std::endl;
  // }

  for (int i = 0; i < N - 1; i++) {
    pq.push(
        {xVec[i].idx, xVec[i + 1].idx, abs(xVec[i].coord - xVec[i + 1].coord)});
    pq.push(
        {yVec[i].idx, yVec[i + 1].idx, abs(yVec[i].coord - yVec[i + 1].coord)});
    pq.push(
        {zVec[i].idx, zVec[i + 1].idx, abs(zVec[i].coord - zVec[i + 1].coord)});
  }
  std::cout << solve() << std::endl;
  return 0;
}