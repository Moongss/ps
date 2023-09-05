#include <iostream>

int inOrderIdx[100001];
int inOrder[100001];
int postOrder[100001];

//post의 마지막이 루트고, inorder에서 루트 값에 대한 idx를
//기준으로 좌우 나눠서 서브트리 만드는건 잘 했는데
//postOrder을 나누는걸 서브트리 개수가 아니라
//이상한 기준으로 잡아서 시간날렸음.
void solve(int inStart, int inEnd, int postStart, int postEnd) {

  if (inStart > inEnd || postStart > postEnd) return;

  int rootIdx = inOrderIdx[postOrder[postEnd]]; //postOrder을 안해줘서 터짐..
  int leftSubTreeNum = rootIdx - inStart;

  std::cout << inOrder[rootIdx] << " "; //preorder

  solve(inStart, rootIdx - 1, postStart, postStart + leftSubTreeNum - 1);
  solve(rootIdx + 1, inEnd, postStart + leftSubTreeNum, postEnd - 1);
}

int main() {
  int N;
  int tmp;
  
  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> tmp;
    inOrder[i] = tmp;
    inOrderIdx[tmp] = i;
  }

  for (int i = 0; i < N; i++) {
    std::cin >> postOrder[i];
  }

  solve(0, N - 1, 0, N - 1);

  return 0;
}