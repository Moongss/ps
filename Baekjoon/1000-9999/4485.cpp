#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N;
int arr[125][125];
int dist[125][125];

int dx[4] = {-1, 1, 0 ,0};
int dy[4] = {0, 0, -1, 1};
int cases = 0;

int main() {
    fastio;
    while (true) {
        cin >> N;
        if (N == 0) break;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
                dist[i][j] = INT_MAX;
            }
        }

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({-arr[0][0], {0, 0}});
        dist[0][0] = arr[0][0];

        while (!pq.empty()) {
            int cost = -pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            if (dist[x][y] < cost) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (!(0 <= nx && nx < N && 0 <= ny && ny < N)) continue;
                if (dist[nx][ny] > cost + arr[nx][ny]) {
                    dist[nx][ny] = cost + arr[nx][ny];
                    pq.push({-dist[nx][ny], {nx, ny}});
                }
            }
        }

        cases++;
        cout << "Problem " << cases << ": " << dist[N - 1][N - 1] << endl;
    }
    return 0;
}