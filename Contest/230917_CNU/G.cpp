#include <iostream>
#include <queue>
#include <algorithm>

int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    int N, A, B;
    int P[100000];
    int Q[100000];
    
    std::cin >> N >> A >> B;
    long long result = 0;

    std::priority_queue<std::pair<int, std::pair<int, int> > > pq;

    for (int i = 0; i < N; i++) {
        std::cin >> P[i] >> Q[i];
        
        pq.push(std::make_pair(Q[i] - P[i], std::make_pair(P[i], Q[i])));
    }

    for (int i = 0; i < N; i++) {
        // std::cout << "elem : " << pq.top().second.first << ", " << pq.top().second.second << std::endl;
        if (A) {
            result += pq.top().second.first;
            A--;
        } else {
            result += pq.top().second.second;
        }
        pq.pop();
    }

    std::cout << result << std::endl;
    return 0;
}