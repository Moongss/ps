#include <iostream>
#include <queue>

int N;
std::priority_queue<std::pair<long long, int> > pq;
long long cnt[250000] = {0, };
bool valid[250000] = {true, };

int main() {
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        long long tmp;
        std::cin >> tmp;

        valid[i] = true;
        pq.push(std::make_pair(tmp + 1, i));
    }

    long long result = 0;
    while (!pq.empty()) {
        std::pair<long long, int> elem = pq.top();
        pq.pop();

        long long val = elem.first;
        int idx = elem.second;

        int prev = (idx + N - 1) % N;
        int next = (idx + 1) % N;
        if (valid[prev] && valid[next] && 
            (cnt[prev] + cnt[next] < val ||
            (cnt[prev] + cnt[next] == val && idx % 2 == 1))) {
            result += val;
            valid[idx] = false;
            cnt[prev] = cnt[next] = 0; //never choose.
        }
    }

    std::cout << result << std::endl;
    return 0;
}
