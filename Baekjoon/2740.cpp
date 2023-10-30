#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;

int N, M, K;
int A[100][100];
int B[100][100];
int result[100][100];

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    cin >> M >> K;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int sum = 0;
            for (int k = 0; k < M; k++) {
                sum += A[i][k] * B[k][j];
            }
            result[i][j] = sum;
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}