#include <iostream>
#include <queue>
#include <set>
#include <vector>

#define SPACE 0
#define WALL 1

int N, M;
int map[1000][1000];
int spaceId[1000][1000];
int currentSpaceId = 1;
std::vector<int> spaceCnt;

bool visit[1000][1000] = {
	false,
};
int result[1000][1000] = {
	0,
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
}

void printResult() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == WALL) {
				std::set<int> check;
				result[i][j]++;
				for (int k = 0; k < 4; k++) {
					int nextX = i + dx[k];
					int nextY = j + dy[k];
					if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
						continue;
					if (map[nextX][nextY] == WALL)
						continue;
					if (check.find(spaceId[nextX][nextY]) != check.end())
						continue;
					check.insert(spaceId[nextX][nextY]);
					result[i][j] += spaceCnt[spaceId[nextX][nextY]];
				}
			}
			std::cout << result[i][j] % 10;
		}
		std::cout << "\n";
	}
}

void findSpace(int x, int y) {
	std::queue<std::pair<int, int>> q;

	int cnt = 1;
	spaceId[x][y] = currentSpaceId;
	visit[x][y] = true;
	q.push({x, y});
	while (!q.empty()) {
		std::pair<int, int> elem = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextX = elem.first + dx[i];
			int nextY = elem.second + dy[i];
			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
				continue;
			if (visit[nextX][nextY])
				continue;
			if (map[nextX][nextY] == WALL)
				continue;

			cnt++;
			visit[nextX][nextY] = true;
			spaceId[nextX][nextY] = currentSpaceId;
			q.push({nextX, nextY});
		}
	}
	spaceCnt.push_back(cnt);
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == SPACE && !visit[i][j]) {
				findSpace(i, j);
				currentSpaceId++;
			}
		}
	}

	printResult();
}

int main() {
	// std::ios_base::sync_with_stdio(false);
	// std::cin.tie(0);
	// std::cout.tie(0);

	std::cin >> N >> M;
	spaceCnt.push_back(0);

	init();
	solve();
	return 0;
}