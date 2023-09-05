#include <iostream>

#define LEFT 0
#define RIGHT 1

int preOrder[10001] = {0, };

void printTree(int rootIdx, int maxIdx) {
  if (rootIdx >= maxIdx)
    return;
  
  int rootNode = preOrder[rootIdx];
  int middlePoint;
  for (middlePoint = rootIdx + 1; middlePoint < maxIdx; middlePoint++) {
    if (preOrder[middlePoint] > rootNode)
      break;
  }

  printTree(rootIdx + 1, middlePoint);
  printTree(middlePoint, maxIdx);
  std::cout << rootNode << std::endl;
}


int main() {
  int nodeCnt = 0;
  
  while (std::cin >> preOrder[nodeCnt]) {
    nodeCnt++;
  }

  printTree(0, nodeCnt);
  return 0;
}