#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
int N, K;
int A[500000];
int tmp[500000];
int cnt = 0;
int result = -1;

void merge(int s, int mid, int e) {
    int i = s;
    int j = mid + 1;
    int t = 1;
    while (i <= mid && j <= e) {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }

    while (i <= mid) {
        tmp[t++] = A[i++];
    }
    while (j <= e) {
        tmp[t++] = A[j++];
    }

    i = s; t = 1;
    while (i <= e) {
        cnt++;
        if (cnt == K) result = tmp[t];
        A[i++] = tmp[t++];
    }
}

void mergeSort(int s, int e) {
    if (s < e) {
        int mid = (s + e) / 2;
        mergeSort(s, mid);
        mergeSort(mid + 1, e);
        merge(s, mid, e);
    }
}

int main() {
    fastio;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        A[i] = tmp;
    }
    mergeSort(0, N - 1);
    cout << result << endl;
    return 0;
}