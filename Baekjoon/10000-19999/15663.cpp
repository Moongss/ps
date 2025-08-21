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
  if (currentIndex == M + 1) {  // index�� 1���� �����ϴ°ɷ� �ع���;
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

  //���� �迭 ���� ���� ������ count�ؼ� ������ ����� �ʿ� ���� ������
  //����ߴ����� ���θ� �Ǵ��ؼ� true/false�� üũ�ϸ� ���� ������?
  //�װ͵� �׷��� �迭������ �ʹ� ���� �ϴµ�? �̰ŋ����� ������?
  //�ٵ� �ٲ㵵 3�ʸ� �پ��µ�.. ��....

  // int prevNumber = 0;
  int prevIndex = 0;
  for (int i = 1; i <= N; i++) {
    //���� index�� value�� ���� value�� �ٸ���, �湮���� �ʾҴٸ�?
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

  // �ߺ��� �������� �ʰ� ī��Ʈ ���� �͵� �ȸ���� ������ä�� �����ٸ�? �
  // ������ �־�� �ұ�

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

  // �Ϲ�ȭ�� ���Ѿ��Ѵ�...? �� ����� �غ���.
  // solve((currentIndex < N) ? currentIndex : N, M, 1);

  // N, M�� �������� ������.
  solve(1);
}