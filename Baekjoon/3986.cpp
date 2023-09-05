#include <iostream>
#include <stack>
#include <string>

int main() {
  int N;
  int result = 0;

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::stack<int> st;
    std::string str;
    std::cin >> str;
    for (int i = 0; i < str.length(); i++) {
      if (st.size() > 0 && st.top() == str[i])
        st.pop();
      else
        st.push(str[i]);
    }
    if (st.size() == 0)
      result++;
  }

  std::cout << result << std::endl;
  return 0;
}