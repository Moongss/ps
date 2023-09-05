#include <iostream>

int N;
int result = 0;

int queens[16]; //queens[1] = 2, means (1, 2) has queen. (1, 1) ~ (15, 15)

void print() 
{
  for (int i = 1; i <= N; i++) {
    std::cout << queens[i] << " ";
  }  
  std::cout << std::endl;
}

int abs(int a, int b) {
  if (a > b)
    return (a - b);
  return (b - a);
}

bool isValid(int currentIdx) {
  //기존 점들과...
  for (int i = 1; i < currentIdx; i++) {
    if (i == currentIdx || queens[i] == queens[currentIdx])
      return false;
    if (abs(i, currentIdx) == abs(queens[i], queens[currentIdx]))
      return false;
  }
  return true;
}

void solve(int currentIdx) {
  if (currentIdx == N + 1) {
    result++;
    return;
  }

  for (int i = 1; i <= N; i++) {
    queens[currentIdx] = i;
    if (isValid(currentIdx))
      solve(currentIdx + 1);
  }
}

int main() {
  std::cin >> N;

  for (int i = 1; i <= 15; i++) {
    queens[i] = 1;
  }
  solve(1);

  std::cout << result;
  return 0;
}