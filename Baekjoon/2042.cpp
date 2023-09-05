#include <iostream>

int N, M, K;
long long arr[1000001];
long long tree[4000001];

long long setTree(int start, int end, int idx) {
  if (start == end) {
    tree[idx] = arr[start];
    return tree[idx];
  }

  int mid = (start + end) / 2;
  tree[idx] = setTree(start, mid, idx * 2) + setTree(mid + 1, end, idx * 2 + 1);
  return tree[idx];
}

long long sum(int start, int end, int left, int right, int idx) {
  if (left > end || start > right)
    return 0;
  if (left <= start && end <= right)
    return tree[idx];

  int mid = (start + end) / 2;
  return sum(start, mid, left, right, idx * 2) +
         sum(mid + 1, end, left, right, idx * 2 + 1);
}

void modify(int start, int end, int target, long long diff, int idx) {

  if (target < start || target > end)
    return;

  tree[idx] += diff;
  if (start == end)
    return;
  int mid = (start + end) / 2;
  modify(start, mid, target, diff, idx * 2);
  modify(mid + 1, end, target, diff, idx * 2 + 1);
}

int main() {
  std::cin >> N >> M >> K;
  for (int i = 1; i <= N; i++)
    std::cin >> arr[i];

  setTree(1, N, 1);
  // for (int i = 1; i <= N; i++)
  //   std::cout << "Tree : " << tree[i] << std::endl;

  for (int i = 0; i < M + K; i++) {
    long long flag, target, num;
    std::cin >> flag >> target >> num;

    if (flag == 1) {
      // modify
      modify(1, N, target, num - arr[target], 1);
      arr[target] = num;
    } else {
      // sum
      std::cout << sum(1, N, target, num, 1) << std::endl;
    }
  }

  return 0;
}