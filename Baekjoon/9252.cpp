#include <iostream>
#include <string>

int max(int a, int b) { return (a > b ? a : b); }

int main(void) {
  int dp[1001][1001] = {0};
  std::string source;
  std::string dest;

  std::cin >> source >> dest;

  // add padding -> 관용이라 한다.
  source = '0' + source;
  dest = '0' + dest;

  for (size_t i = 1; i < source.length(); i++) {
    for (size_t j = 1; j < dest.length(); j++) {
      if (source[i] == dest[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  char LCS[1001] = {
      0,
  };
  int sourceIdx = source.length() - 1;
  int destIdx = dest.length() - 1;
  int LCSLength = dp[sourceIdx][destIdx];

  std::cout << LCSLength << std::endl;
  while (LCSLength) {
    if (source[sourceIdx] == dest[destIdx]) {
      LCSLength--;
      LCS[LCSLength] = source[sourceIdx];
      sourceIdx--; destIdx--;
    } else {
      if (dp[sourceIdx - 1][destIdx] > dp[sourceIdx][destIdx - 1])
        sourceIdx--;
      else
        destIdx--;
    }
  }

  std::cout << LCS << std::endl;
  return 0;
}