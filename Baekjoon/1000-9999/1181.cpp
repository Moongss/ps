#include <iostream>
#include <string>
#include <algorithm>
#include <list>

int main() {
   	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
    
  int N;
  int minLength = 51;
  int maxLength = 0;
  std::string word;
  std::list<std::string> wordList;

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> word;
    if (std::find(wordList.begin(), wordList.end(), word) == wordList.end()) {
      minLength = (minLength > word.length()) ? word.length() : minLength;
      maxLength = (maxLength < word.length()) ? word.length() : maxLength;
      wordList.push_back(word);
    }
  }

  wordList.sort();
  for (int targetLength = minLength; targetLength <= maxLength; targetLength++) {
    for (std::list<std::string>::iterator i = wordList.begin(); i != wordList.end(); i++) {
      if ((*i).length() == targetLength)
        std::cout << *i << '\n';
    }
  }
}