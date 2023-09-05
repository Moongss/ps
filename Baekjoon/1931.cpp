#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

bool compare(std::pair<int, int> a, std::pair<int, int> b) {
  if (a.second == b.second)
    return a.first < b.first;
  return a.second < b.second;
}

int main() {
    std::vector<std::pair<int, int> > input;
    int N;
    int start, end;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> start >> end;
        input.push_back(std::pair<int, int>(start, end));
    }

    std::sort(input.begin(), input.end(), compare);

    int cnt = 1;
    int tmp = input[0].second;
    for (int i = 1; i < N; i++) {
        if (input[i].first >= tmp) {
            cnt++;
            tmp = input[i].second;
        }
    }

    std::cout << cnt << std::endl;
  
    return 0;
}