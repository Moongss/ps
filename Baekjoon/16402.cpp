#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

int N, M;
int parent[501];
std::map<std::string, int> nameToIdx;
std::map<int, std::string> idxToName;

int getParent(int x) {
  if (x == parent[x])
    return x;
  return parent[x] = getParent(parent[x]);
}

void setParent(int win, int lose) {
  int winParent = getParent(win);
  int loseParent = getParent(lose);

  if (winParent == loseParent) {
    parent[win] = win;
    parent[loseParent] = win;
  } else {
    win = getParent(win);
    lose = getParent(lose);
    parent[lose] = win;
  }
}

// https://gaga.tistory.com/63
int main() {

  std::cin >> N >> M;
  std::cin.ignore();

  std::string name;
  for (int i = 0; i < N; i++) {
    getline(std::cin, name);
    nameToIdx[name] = i;
    idxToName[i] = name;
    parent[i] = i;
    // std::cout << "name : " << name << std::endl;
  }

  std::string condition;
  for (int i = 0; i < M; i++) {
    getline(std::cin, condition);
    // std::cout << "condition: " << condition << std::endl;
    std::istringstream ss(condition);
    std::string strBuffer;
    std::vector<std::string> tmp;

    int win;
    int lose;
    while (getline(ss, strBuffer, ',')) {
      tmp.push_back(strBuffer);
    }

    if (tmp[2][0] == '1') {
      win = nameToIdx[tmp[0]];
      lose = nameToIdx[tmp[1]];
    } else {
      win = nameToIdx[tmp[1]];
      lose = nameToIdx[tmp[0]];
    }
    setParent(win, lose);
    tmp.clear();
  }

  // for (int i = 0; i < N; i++) {
  //   std::cout << " i 's parent : " << parent[i] << std::endl;
  // }

  std::vector<std::string> result;
  for (int i = 0; i < N; i++) {
    if (parent[i] == i)
      result.push_back(idxToName[i]);
  }

  std::sort(result.begin(), result.end());

  std::cout << result.size() << std::endl;
  for (int i = 0; i < result.size(); i++) {
    std::cout << result[i] << std::endl;
  }

  return 0;
}