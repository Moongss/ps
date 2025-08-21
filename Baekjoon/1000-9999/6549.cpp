#include <iostream>

typedef long long ll;

ll arr[100001];
int tree[400004];
int N, M;

int init(int start, int end, int node) {
  if (start == end)
    return tree[node] = start; // minHeight idx

  int mid = (start + end) / 2;

  int leftChild = init(start, mid, node * 2);
  int rightChild = init(mid + 1, end, node * 2 + 1);

  // std::cout << "node : " << node << "left/right : " << leftChild << "/"
  //           << rightChild << std::endl;
  if (arr[leftChild] <= arr[rightChild]) {
    tree[node] = leftChild;
  } else {
    tree[node] = rightChild;
  }
  return tree[node];
}

int findMinHeightIdx(int start, int end, int left, int right, int node) {
  if (left > end || start > right)
    return -1;
  if (left <= start && end <= right)
    return tree[node];

  int mid = (start + end) / 2;

  int leftChild = findMinHeightIdx(start, mid, left, right, node * 2);
  int rightChild = findMinHeightIdx(mid + 1, end, left, right, node * 2 + 1);

  if (leftChild == -1)
    return rightChild;
  else if (rightChild == -1)
    return leftChild;
  else if (arr[leftChild] <= arr[rightChild])
    return leftChild;
  return rightChild;
}

ll solve(int start, int end) {

  // std::cout << "solve start/end : " << start << "/" << end << std::endl;
  int minHeightIdx = findMinHeightIdx(1, N, start, end, 1);
  // std::cout << "minHeightIdx : " << minHeightIdx << std::endl;
  ll area = (end - start + 1) * arr[minHeightIdx];

  if (start < minHeightIdx) {
    ll leftSubTreeArea = solve(start, minHeightIdx - 1);
    if (area < leftSubTreeArea)
      area = leftSubTreeArea;
  }
  if (minHeightIdx < end) {
    ll rightSubTreeArea = solve(minHeightIdx + 1, end);
    if (area < rightSubTreeArea)
      area = rightSubTreeArea;
  }

  return area;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  while (true) {
    std::cin >> N;
    if (N == 0)
      break;
    for (int i = 1; i <= N; i++) {
      std::cin >> arr[i];
    }
    init(1, N, 1);

    // for (int i = 1; i <= 4 * N; i++) {
    //   if (tree[i] != 0)
    //     std::cout << "i : " << i << ", square : " << tree[i] << std::endl;
    // }

    std::cout << solve(1, N) << "\n";
  }

  return 0;
}