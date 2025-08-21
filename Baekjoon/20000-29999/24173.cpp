#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N;
ll K;
vector<ll> v;
pair<int, int> result;
void heapify(int i, int n) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest;

    if (right <= n) {
        if (v[left] < v[right])
            smallest = left;
        else
            smallest = right;
    }
    else if (left <= n) {
        smallest = left;
    }
    else return;

    if (v[smallest] < v[i]) {
        K--;
        swap(v[i], v[smallest]);
        if (K == 0) {
            result = {min(v[i], v[smallest]), max(v[i], v[smallest])};
            cout << result.first << " " << result.second << endl;
            exit(0);
        }
        heapify(smallest, n);
    }
}

void build_min_heap() {
    for (int i = N / 2; i >= 1; i--) {
        heapify(i, N);
    }
}

void heap_sort() {
    build_min_heap();
    for (int i = N; i >= 2; i--) {
        swap(v[1], v[i]);
        K--;
        if (K == 0) {
            result = {min(v[1], v[i]), max(v[1], v[i])};
            cout << result.first << " " << result.second << endl;
            exit(0);
        }
        heapify(1, i - 1);
    }
}

int main() {
    fastio;
    
    cin >> N >> K;
    v.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    heap_sort();
    cout << -1 << endl;
    return 0;
}