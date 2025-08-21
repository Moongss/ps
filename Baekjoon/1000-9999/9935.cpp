#include <iostream>
#include <string>
#include <vector>

int main() {
  int cnt = 0;
  std::string str;
  std::string boomStr;
  std::vector<char> save;

  std::cin >> str >> boomStr;
  for (int i = 0; i < str.length(); i++) {

    save.push_back(str[i]);
    if (save.size() >= boomStr.size()) {
      cnt = 0;
      for (int j = 0; j < boomStr.length(); j++) {
        if (save[save.size() - 1 - j] == boomStr[boomStr.size() - 1 - j]) {
          cnt++;
        }
      }

      if (cnt == boomStr.length()) {
        for (int j = 0; j < boomStr.length(); j++) {
          save.pop_back();
        }
      }
    }
  }

  if (save.size() == 0)
    std::cout << "FRULA\n";
  else {
    for (int i = 0; i < save.size(); i++) {
      std::cout << save[i];
    }
  }
  return 0;
}