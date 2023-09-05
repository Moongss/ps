#include <algorithm>
#include <iostream>

using namespace std;

bool check[9] = {false};
int save[9];
int input[9];
int N, M;

// range : N
// cnt : M
void solve(int currentIndex) {
  if (currentIndex == M + 1) {  // index를 1부터 시작하는걸로 해버림;
    for (int i = 1; i <= M; i++) {
      cout << save[i] << " ";
    }
    cout << "\n";
    return;
  }

  // int prevIndex = 0;
  // for (int i = 1; i <= N; i++) {
  //   if (input[prevIndex] == input[i]) continue;
  //   if (check[i] < cntPerNumber[i]) {
  //     save[currentIndex] = input[i];
  //     check[i]++;
  //     solve(currentIndex + 1);
  //     check[i]--;
  //   }
  //   prevIndex = i;
  // }

  //굳이 배열 만들어서 기존 정보를 count해서 일일히 계산할 필요 없이 기존에
  //사용했는지의 여부만 판단해서 true/false로 체크하면 되지 않을까?
  //그것도 그렇고 배열접근을 너무 많이 하는데? 이거떄문에 터졌나?
  //근데 바꿔도 3초만 줄었는데.. 음....

  // int prevNumber = 0;
  int prevIndex = 0;
  for (int i = 1; i <= N; i++) {
    //기존 index의 value가 현재 value랑 다르고, 방문하지 않았다면?
    if (input[prevIndex] != input[i] && !check[i]) {
      save[currentIndex] = input[i];
      check[i] = true;
      solve(currentIndex + 1);
      check[i] = false;
      prevIndex = i;
    }
  }
}

int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> input[i];
  }

  // sort
  // sort(input, input + N);

  int tmp;
  for (int i = 1; i <= N - 1; i++) {
    for (int j = i + 1; j <= N; j++) {
      if (input[i] > input[j]) {
        tmp = input[i];
        input[i] = input[j];
        input[j] = tmp;
      }
    }
  }

  // for (int i = 1; i <= N; i++) {
  //   cout << "DEBUG : VALUE - " << input[i] << endl;
  // }

  // 중복을 제외하지 않고 카운트 같은 것도 안만들고 정렬한채로 돌린다면? 어떤
  // 조건이 있어야 할까

  // int currentValue = 0;
  // int currentIndex = 0;
  // for (int i = 1; i <= N; i++) {
  //   if (currentValue != input[i]) {
  //     currentValue = input[i];
  //     currentIndex++;
  //   }
  //   cntPerNumber[currentIndex]++;
  // }

  // arr to make set
  // for (int i = 2; i <= N; i++) {
  //   if (input[i - 1] == input[i]) {
  //     for (int j = i; j <= N - 1; j++) {
  //       input[j] = input[j + 1];
  //     }
  //     input[N] = 0;
  //   }
  // }

  // 일반화를 시켜야한다...? 싹 지우고 해보자.
  // solve((currentIndex < N) ? currentIndex : N, M, 1);

  // N, M도 전역으로 빼두자.
  solve(1);
}