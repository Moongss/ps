#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;
using ld = long double;

int N, S;
vector<int> arr;
vector<int> l;
vector<int> r;
int main() {
    fastio;
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }

    if (N == 1) {
        cout << (arr[0] == S ? 1 : 0) << endl;
        return 0;
    }

    int half = N / 2;
    for (int i = 1; i < (1 << half); i++) {
        int sum = 0;
        for (int j = 0; j < half; j++) {
            if (i & (1 << j)) sum += arr[j];
        }
        l.push_back(sum);
    }
    for (int i = 1; i < (1 << (N - half)); i++) {
        int sum = 0;
        for (int j = 0; j < N - half; j++) {
            if (i & (1 << j)) sum += arr[half + j];
        }
        r.push_back(sum);
    }

    ll result = 0;
    sort(r.begin(), r.end());

    for (auto &elem : r) {
        result += (elem == S);
    }
    for (auto &elem : l) {
        result += (elem == S);
        result += upper_bound(r.begin(), r.end(), S - elem) - lower_bound(r.begin(), r.end(), S - elem);
    }

    cout << result << endl;
    return 0;
}