#include <iostream>

#define UPDATE 1

typedef long long ll;
typedef std::pair<int, int> pair;

int tree[4000004] = {0, };
int N, M;

void update(int start, int end, int target, int node) {
  if (target < start || end < target)
    return;
  if (start == end) {
    tree[node] = 1;
    return;
  }

  int mid = (start + end) / 2;
  update(start, mid, target, node * 2); 
  update(mid + 1, end, target, node * 2 + 1); 
  tree[node] = tree[node * 2] + tree[node * 2 + 1]; //same as ++;
}

int getPrefixSum(int start, int end, int left, int right, int node) {
  if (right < start || end < left)
    return 0;
  if (left <= start && end <= right) {
    return tree[node];
  }

  int mid = (start + end) / 2;
  return getPrefixSum(start, mid, left, right, node * 2) + 
         getPrefixSum(mid + 1, end, left, right, node * 2 + 1);
}

int main() {
  std::cin.tie(0)->sync_with_stdio(0);
  
  std::cin >> N;
  long result = 0;
  for (int i = 1; i <= N; i++) {
    int idx;
    std::cin >> idx;
    
    result += getPrefixSum(1, N, idx, N, 1);
    update(1, N, idx, 1);
  }

  std::cout << result << std::endl;
  return 0;
}