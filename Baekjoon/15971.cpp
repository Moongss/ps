#include <iostream>
#include <queue>
#include <vector>

int N, S, E;
std::vector<std::pair<int, int>> connect[100001];
bool visit[100001] = {
	false,
};

void solve(int now, int total, int maxLength) {
	visit[now] = true;
    if (now == E) {
        std::cout << total - maxLength << std::endl;
        return;
    }
    
	for (int i = 0; i < connect[now].size(); i++) {
		int next = connect[now][i].first;
		int length = connect[now][i].second;
		if (visit[next])
			continue;

		total += length;
		solve(next, total, std::max(length, maxLength));
		total -= length;
	}
}

int main() {
	std::cin >> N >> S >> E;

	for (int i = 0; i < N - 1; i++) {
		int a, b, length;
		std::cin >> a >> b >> length;
		connect[a].push_back({b, length});
		connect[b].push_back({a, length});
	}
	if (S == E) {
		std::cout << 0 << std::endl;
		return 0;
	}
	solve(S, 0, 0);
	return 0;
}