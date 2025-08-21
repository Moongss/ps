#include <iostream>
#include <queue>
#include <vector>

int N, Q;
int a, b, u, v;

std::vector<int> connect[200001];
int parent[200001];
bool visited[200001] = {
	false,
};
bool isCycle[200001] = {
	false,
};
bool isFindCycle = false;

void denoteCycle(int start, int end) {
	while (start != end) {
		isCycle[start] = true;
		start = parent[start];
	}
	isFindCycle = true;
	isCycle[start] = true;
}

void getCycle(int now, int from) {
	for (int i = 0; i < connect[now].size(); i++) {
		int next = connect[now][i];
		if (next == from)
			continue;

		if (!visited[next]) {
			visited[next] = true;
			parent[next] = now;
			getCycle(next, now);
		} else if (!isFindCycle) {
			denoteCycle(now, next);
			return;
		}
	}
}

void makeSubTree(int now, int treeId) {
	parent[now] = treeId;

	for (int i = 0; i < connect[now].size(); i++) {
		int next = connect[now][i];
		if (isCycle[next])
			continue;
		if (!parent[next])
			makeSubTree(next, treeId);
	}
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> N >> Q;

	for (int i = 0; i < N; i++) {
		std::cin >> a >> b;
		connect[a].push_back(b);
		connect[b].push_back(a);
	}

	visited[1] = true;
	getCycle(1, 1);
	// for (int i = 1; i <= N; i++) {
	// 	std::cout << i << "'s cycle : " << isCycle[i] << std::endl;
	// }

	for (int i = 1; i <= N; i++) {
		parent[i] = 0;
	}

	for (int i = 1; i <= N; i++) {
		if (isCycle[i]) {
			makeSubTree(i, i);
		}
	}

	for (int i = 0; i < Q; i++) {
		std::cin >> u >> v;
		if (parent[u] != parent[v])
			std::cout << 2 << "\n";
		else
			std::cout << 1 << "\n";
	}

	return 0;
}