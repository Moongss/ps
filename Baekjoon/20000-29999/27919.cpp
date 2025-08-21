#include <iostream>
using namespace std;

int cnt[4]; //UDPC

int main(void)
{
  int maxV = -1;
  string str; cin >> str;

  if (str.length() == 0) {
    cout << 'C' << endl;
    return 0;
  }

  for (int i = 0; i < str.length(); i++) {
    if (str[i] == 'U') cnt[0]++;
    if (str[i] == 'D') cnt[1]++;
    if (str[i] == 'P') cnt[2]++;
    if (str[i] == 'C') cnt[3]++;
  }

  int UC = cnt[0] + cnt[3];
  int DP = cnt[1] + cnt[2];

  if (UC > (DP + 1) / 2) cout << 'U';
  if (DP > 0) cout << "DP";
  cout << endl;
  return 0;
}