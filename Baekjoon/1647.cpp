#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

bool visit[100001] = {0, };
std::vector<std::pair<int, int> > info[100001];

int N, M;
int solve() {
    int sum = 0;
    int max = -1;

    //cost, end
    std::priority_queue<std::pair<int, int> > pq;
    visit[1] = true;
    
    for (int i = 0; i < info[1].size(); i++) {
        int end = info[1][i].first;
        int cost = info[1][i].second;

        pq.push({-cost, end});
    }

    while (!pq.empty()) {
        std::pair<int, int> minElement = pq.top();
        pq.pop();

        int cost = -minElement.first;
        int v = minElement.second;

        if (!visit[v]) {
            sum += cost;
            if (cost > max)
                max = cost;

            visit[v] = true;
            for (int i = 0; i < info[v].size(); i++) {
                if (!visit[info[v][i].first])
                    pq.push({-info[v][i].second, info[v][i].first});
            }
        }
    }

    return sum - max;
}

int main() {
    int start, end, cost;
    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        std::cin >> start >> end >> cost;
        info[start].push_back({end, cost});
        info[end].push_back({start, cost});
    }

    std::cout << solve() << std::endl;
    return 0;
}
