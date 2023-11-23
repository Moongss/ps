#include <iostream>
using namespace std;

bool arr[1000000];
int main(void)
{
  int N; cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];

  int idx = 0;
  int cnt = 0;
  while (idx < N) {
    if (arr[idx] == 1) {
      cnt++;
      if (idx + 1 < N) arr[idx + 1] = !arr[idx + 1];
      if (idx + 2 < N) arr[idx + 2] = !arr[idx + 2];
    }
    idx++;
  }
  cout << cnt << endl;
  return 0;
}