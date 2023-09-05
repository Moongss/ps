#include <iostream>

typedef long long ll;

int arr[1000001] = {
    0,
};
ll tree[4000004];

int N, M;

// ll init(int start, int end, int node) {
//   if (start == end)
//     return tree[node] = arr[start];

//   int mid = (start + mid) / 2;
//   return tree[node] =
//              init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
// }

ll sum(int start, int end, int left, int right, int node) {
  if (left > end || start > right)
    return 0;
  if (left <= start && end <= right)
    return tree[node];

  int mid = (start + end) / 2;
  return sum(start, mid, left, right, node * 2) +
         sum(mid + 1, end, left, right, node * 2 + 1);
}

void update(int start, int end, int target, int diff, int node) {
  if (target < start || end < target)
    return;

  tree[node] += diff;
  int mid = (start + end) / 2;
  if (start == end)
    return;

  update(start, mid, target, diff, node * 2);
  update(mid + 1, end, target, diff, node * 2 + 1);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int flag, a, b;
    std::cin >> flag >> a >> b;

    if (flag == 0) {
      if (a < b)
        std::cout << sum(1, N, a, b, 1) << "\n";
      else
        std::cout << sum(1, N, b, a, 1) << "\n";
    } else {
      update(1, N, a, b - arr[a], 1);
      arr[a] = b;
    }
  }
  return 0;
}
