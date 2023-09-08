#include <bits/stdc++.h>
using namespace std;

int n;
std::vector<int> v;
std::string s;
int q;

std::vector<int> result;

int getXOR(int x, int y) {
  int ans = 0;
  for (int i = 0; i <= 31; i++) {
    if (((1LL << i) & x) != ((1LL << i) & y)) {
      ans |= (1LL << i);
    }
  }
  return ans;
}

void solve1() {
    int start, end;

    std::cin >> start >> end;
    start--;
    end--;

    std::string result = "";
    for (int i = 0; i <= s.length(); i++) {
        if (start <= i && i <= end) {
            if (s[i] == '0')
                result += '1'; // TLE: not use prefix-sum, O(N)
            else
                result += '0';
        }else {
            result += s[i];
        }
    }

    // std::cout << "TMP : " << result << std::endl;
    s = result;
}

void solve2() {
    int flag;
    std::cin >> flag;
    std::vector<int> tmp;

    tmp.clear();
    if (flag == 0) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') 
                tmp.push_back(v[i]);
        }
    }else {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') 
                tmp.push_back(v[i]);
        }
    }

    if (tmp.size() == 0)
        result.push_back(0);
    else if (tmp.size() == 1)
        result.push_back(tmp.front());
    else {
        int idx = 1;
        int a = tmp[0];
        while (idx < tmp.size()) {
            int b = tmp[idx];
            a = getXOR(a, b); //TLE -> xor을 쿼리처럼 생각해서 했으면... 어땠을까...
            idx++;
        }
        result.push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    std::cin >> t;

    while (t--) {
        result.clear();
        v.clear();
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            int tmp;
            std::cin >> tmp;
            v.push_back(tmp);
        }
        std::cin >> s;
        std::cin >> q;
        while (q--) {
            int tp;

            std::cin >> tp;
            if (tp == 1) {
                solve1();
            } else if (tp == 2) {
                solve2();
            }
        }

        // std::cout << "RESULT" << std::endl;
        for (int i = 0; i < result.size(); i++) {
            std::cout << result[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}