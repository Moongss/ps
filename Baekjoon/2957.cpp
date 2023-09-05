#include <iostream>
#include <map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int N;
	long cnt = 0;
	std::map<int, int> tree;

	tree.insert({0, -42});
	tree.insert({300001, -42});

	std::cin >> N;
	for (int i = 0; i < N; i++) {
		int key;
		std::cin >> key;
		if (i == 0)
			tree.insert({key, 0});
		else {
			std::map<int, int>::iterator leftNode, rightNode;
			rightNode = tree.upper_bound(key);
			leftNode = rightNode;
			leftNode--;

			int level = std::max(leftNode->second, rightNode->second) + 1;
			tree.insert({key, level});
			cnt += level;
		}
		std::cout << cnt << "\n";
	}

	return 0;
}