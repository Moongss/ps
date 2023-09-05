#include <iostream>
#include <queue>
#include <set>
#include <vector>

int N, M;
int map[1000][1000];
int shapeId[1000][1000];
int currentShapeId = 1;
std::vector<int> shapeCnt;

bool visit[1000][1000] = {
	false,
};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cin >> map[i][j];
		}
	}
}

void printResult() {
	int max = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp = 0;
			if (map[i][j] == 0) {
				std::set<int> check;
				tmp++;
				for (int k = 0; k < 4; k++) {
					int nextX = i + dx[k];
					int nextY = j + dy[k];
					if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
						continue;
					if (map[nextX][nextY] == 0)
						continue;
					if (check.find(shapeId[nextX][nextY]) != check.end())
						continue;
					check.insert(shapeId[nextX][nextY]);
					tmp += shapeCnt[shapeId[nextX][nextY]];
				}
			}
			max = (max < tmp) ? tmp : max;
		}
	}

	std::cout << max << std::endl;
}

void findShape(int x, int y) {
	std::queue<std::pair<int, int>> q;

	int cnt = 1;
	shapeId[x][y] = currentShapeId;
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
			if (map[nextX][nextY] == 0)
				continue;

			cnt++;
			visit[nextX][nextY] = true;
			shapeId[nextX][nextY] = currentShapeId;
			q.push({nextX, nextY});
		}
	}
	shapeCnt.push_back(cnt);
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && !visit[i][j]) {
				findShape(i, j);
				currentShapeId++;
			}
		}
	}

	printResult();
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> N >> M;
	shapeCnt.push_back(0);

	init();
	solve();
	return 0;
}