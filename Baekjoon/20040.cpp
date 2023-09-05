#include <iostream>

int N, M;
int parent[500000];

int getParent(int x) {
  if (x == parent[x])
    return x;
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

int main() {
  std::cin >> N >> M;

  for (int i = 0; i < N; i++)
    parent[i] = i;

  int a, b;
  int result = 0;
  for (int i = 1; i <= M; i++) {
    std::cin >> a >> b;
    if (getParent(a) != getParent(b)) // not parent[a], parent[b]
      setParent(a, b);
    else {
      result = i;
      break;
    }
  }

  std::cout << result << std::endl;
  return 0;
}