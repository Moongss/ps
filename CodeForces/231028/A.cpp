#include <bits/stdc++.h>
#define endl "\n"
#define fastio cin.tie(0)->sync_with_stdio(0)

using namespace std;
using ll = long long;


int main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            arr.push_back(tmp);
        }
        if (n == 2) {
            cout << "Yes" << endl;
            continue;
        }

        int a = arr[0];
        bool flag = true;
        for (int i = 0; i < n && flag; i++) {
            if (arr[i] != a)
                flag = false;
        }
        if (flag) {
            cout << "Yes" << endl;
            continue;
        }

        sort(arr.begin(), arr.end());
        int tmp = arr[0];
        int tmp2 = 0;
        int cnt = 0;
        int cnt2 = 0;
        int idx = 0;
        while (idx < n) {
            if (tmp == arr[idx])
                cnt++;
            else {
                tmp2 = arr[idx];
                break;
            }
            idx++;
        }

        flag = true;
        while (idx < n) {
            if (tmp2 == arr[idx])
                cnt2++;
            else {
                flag = false;
                break;
            }
            idx++;
        }

        if (!flag) {
            cout << "No" << endl;
            continue;
        }

        if (cnt == n || cnt2 == n)
            cout << "Yes" << endl;
        else if (n % 2 == 0) {
            if (cnt - cnt2 == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        } else {
            if (abs(cnt - cnt2) == 1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}