#include <iostream>

int inOrderIdx[100001];
int inOrder[100001];
int postOrder[100001];

//post�� �������� ��Ʈ��, inorder���� ��Ʈ ���� ���� idx��
//�������� �¿� ������ ����Ʈ�� ����°� �� �ߴµ�
//postOrder�� �����°� ����Ʈ�� ������ �ƴ϶�
//�̻��� �������� ��Ƽ� �ð�������.
void solve(int inStart, int inEnd, int postStart, int postEnd) {

  if (inStart > inEnd || postStart > postEnd) return;

  int rootIdx = inOrderIdx[postOrder[postEnd]]; //postOrder�� �����༭ ����..
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