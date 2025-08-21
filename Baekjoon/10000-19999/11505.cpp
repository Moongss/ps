#include <iostream>

#define DIVISOR 1000000007

int N, M, K;
long long arr[1000001];
long long tree[4000001];

long long setTree(int start, int end, int idx) {
  if (start == end) {
    tree[idx] = arr[start];
    return tree[idx];
  }

  int mid = (start + end) / 2;
  tree[idx] = ((setTree(start, mid, idx * 2) % DIVISOR) *
               (setTree(mid + 1, end, idx * 2 + 1) % DIVISOR)) %
              DIVISOR;
  return tree[idx];
}

long long mul(int start, int end, int left, int right, int idx) {
  if (left > end || start > right)
    return 1; // not zero
  if (left <= start && end <= right) {
    return tree[idx];
  }

  int mid = (start + end) / 2;
  return ((mul(start, mid, left, right, idx * 2) % DIVISOR) *
          (mul(mid + 1, end, left, right, idx * 2 + 1) % DIVISOR)) %
         DIVISOR;
}

long long modify(int start, int end, long long newNum, int arrIdx, int idx) {
  // like setTree. leaf->root sequence.
  if (arrIdx < start || arrIdx > end)
    return tree[idx]; // not update.
  if (start == end) {
    tree[idx] = newNum; // leaf update
    // std::cout << "modify Tree[idx] : " << tree[idx] << std::endl;
    return tree[idx];
  }

  int mid = (start + end) / 2;
  return tree[idx] =
             ((modify(start, mid, newNum, arrIdx, idx * 2) % DIVISOR) *
              (modify(mid + 1, end, newNum, arrIdx, idx * 2 + 1) % DIVISOR)) %
             DIVISOR;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

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
      modify(1, N, num, target, 1);
      arr[target] = num;
    } else {
      // sum
      std::cout << mul(1, N, target, num, 1) << "\n";
    }
  }

  return 0;
}