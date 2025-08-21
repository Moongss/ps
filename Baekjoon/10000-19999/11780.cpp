#include <iostream>
#include <vector>

#define INF 987654321
int n, m;
int road[101][101];
int log[101][101];

std::vector<int> tmp;

void findPath(int start, int end) {
	if (log[start][end] == 0) {
		tmp.push_back(start);
		tmp.push_back(end);
		return;
	}

	findPath(start, log[start][end]);
	tmp.pop_back();
	findPath(log[start][end], end);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
      road[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int start, end, cost;
		std::cin >> start >> end >> cost;
		road[start][end] = std::min(road[start][end], cost);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
        if (i == j) continue;
				if (road[i][j] > road[i][k] + road[k][j]) {
					road[i][j] = road[i][k] + road[k][j];
					log[i][j] = k;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
      if (road[i][j] == INF) std::cout << "0 ";
      else std::cout << road[i][j] << " ";
		}
		std::cout << "\n";
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
      if (road[i][j] == INF)
        std::cout << "0";
      else {
			  tmp.clear();
        findPath(i, j);
  			std::cout << tmp.size();
  			for (int k = 0; k < tmp.size(); k++)
  				std::cout << " " << tmp[k];
      }
      std::cout << "\n";
		}
	}
	return 0;
}