#include <iostream>

typedef long long ll;
typedef std::pair<int, int> elem;

int arr[100001];
elem tree[400004];

int N, M;

elem init(int start, int end, int node) {
  if (start == end)
    return tree[node] = {arr[start], start};

  int mid = (start + end) / 2;

  elem leftChild = init(start, mid, node * 2);
  elem rightChild = init(mid + 1, end, node * 2 + 1);

  if (leftChild.first < rightChild.first ||
      leftChild.first == rightChild.first &&
          leftChild.second < rightChild.second)
    tree[node] = leftChild;
  else
    tree[node] = rightChild;
  return tree[node];
}

elem update(int start, int end, int targetIdx, int node) {
  if (targetIdx < start || end < targetIdx)
    return tree[node];
  if (start == end && start == targetIdx)
    return tree[node] = {arr[targetIdx], targetIdx};

  int mid = (start + end) / 2;
  elem leftChild = update(start, mid, targetIdx, node * 2);
  elem rightChild = update(mid + 1, end, targetIdx, node * 2 + 1);

  if (leftChild.first < rightChild.first ||
      leftChild.first == rightChild.first &&
          leftChild.second < rightChild.second)
    tree[node] = leftChild;
  else
    tree[node] = rightChild;
  return tree[node];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N;
  for (int i = 1; i <= N; i++)
    std::cin >> arr[i];
  init(1, N, 1);

  std::cin >> M;
  for (int i = 0; i < M; i++) {
    int flag, a, b;
    std::cin >> flag;

    if (flag == 1) {
      std::cin >> a >> b;
      arr[a] = b;
      update(1, N, a, 1);
      // std::cout << "update!" << std::endl;
      // for (int i = 1; i <= 4 * N; i++) {
      //   std::cout << "first : " << tree[i].first
      //             << ", second : " << tree[i].second << std::endl;
      // }
    } else {
      std::cout << tree[1].second << "\n";
    }
  }
  return 0;
}
