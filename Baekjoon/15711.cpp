#include <iostream>
#include <vector>

#define MAX 2000001

int T;
long long A, B;
bool isPrime[MAX];
std::vector<int> prime;

void setPrimeVector() {
  for (int i = 0; i < MAX; i++) {
    isPrime[i] = true;
  }

  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i < MAX; i++) {
    if (isPrime[i]) {
      for (int j = i * 2; j < MAX; j += i) { // not j = i
        isPrime[j] = false;
      }
    }
  }

  for (int i = 2; i < MAX; i++)
    if (isPrime[i])
      prime.push_back(i);
}

bool solve(long long A, long long B) {
  long long sum = A + B;
  bool result = true;

  if (sum == 2)
    return false;
  else if (sum % 2 == 0)
    return true;
  else {
    sum = sum - 2; // even prime number only 2.
    if (sum < MAX)
      return isPrime[sum];

    for (int i = 0; i < prime.size(); i++) {
      if (sum % prime[i] == 0)
        result = false;
    }
  }

  return result;
}
int main() {
  std::cin >> T;

  setPrimeVector();
  for (int i = 0; i < T; i++) {
    std::cin >> A >> B;
    if (solve(A, B))
      std::cout << "YES" << std::endl;
    else
      std::cout << "NO" << std::endl;
  }

  return 0;
}