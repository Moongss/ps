#include <iostream>
#include <vector>

int n, m;
int arr[100001];
std::vector<int> tree[400004];

void init(int start, int end, int node) {
	std::vector<int> &cur = tree[node];
	if (start == end) {
		cur.push_back(arr[start]);
		return;
	}

	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);

	int leftIdx = 0;
	int rightIdx = 0;
	std::vector<int> &left = tree[node * 2];
	std::vector<int> &right = tree[node * 2 + 1];

	while (leftIdx < left.size() && rightIdx < right.size()) {
		if (left[leftIdx] < right[rightIdx]) {
			cur.push_back(left[leftIdx]);
			leftIdx++;
		} else {
			cur.push_back(right[rightIdx]);
			rightIdx++;
		}
	}
	if (leftIdx == left.size()) {
		while (rightIdx < right.size()) {
			cur.push_back(right[rightIdx]);
			rightIdx++;
		}
	} else {
		while (leftIdx < left.size()) {
			cur.push_back(left[leftIdx]);
			leftIdx++;
		}
	}
}

int query(int start, int end, int left, int right, int node, int target) {
	if (left > end || start > right)
		return 0;
	if (left <= start && end <= right)
		return std::lower_bound(tree[node].begin(), tree[node].end(), target) -
			tree[node].begin(); // lowerbound 이용

	int mid = (start + end) / 2;
	return query(start, mid, left, right, node * 2, target) +
		query(mid + 1, end, left, right, node * 2 + 1, target);
}

int main() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		std::cin >> arr[i];

	init(1, n, 1);
	while (m--) {
		int i, j, k;
		std::cin >> i >> j >> k;

		int l = -1e9;
		int r = 1e9;
		int mid;
		int result = -1e9 - 1;
		// lower_bound or upper_bound 사용해서 최댓값을 찾는데,
		// 해당 쿼리가 머지 소트 트리 풀이의 핵심인듯?

		// [start, end] 에서 -1e9 ~ 1e9 까지 잡고 이진탐색 해야되는데
		// -> 첫번째 시도에서 이진탐색 이상하게 함
		while (l <= r) {
			mid = (l + r) / 2;
			int q = query(1, n, i, j, 1, mid);
			if (q < k) {
				result = std::max(mid, result);
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		std::cout << result << "\n";
	}
	return 0;
}