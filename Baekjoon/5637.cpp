#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
  string ans = "";
  while (1) {
    string str; cin >> str;
    int i = 0;
    while (i < str.length()) {
      if ('a' <= str[i] && str[i] <= 'z') {i++; continue;}
      if ('A' <= str[i] && str[i] <= 'Z') {i++; continue;}
      if (str[i] == '-') {i++; continue;}
      break;
    }
    str = str.substr(0, i);
    if (str == "E-N-D") break;
    if (ans.length() < str.length())
      ans = str;
    
  }

  for (auto elem: ans) {
    if ('A' <= elem && elem <= 'Z') cout << (char)(elem - 'A' + 'a');
    else cout << elem;
  }
  cout << endl;
  return 0;
}