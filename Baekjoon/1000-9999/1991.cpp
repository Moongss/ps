#include <iostream>

#define PREORDER 1
#define INORDER 2
#define POSTORDER 3

#define CURRENT_NODE 0
#define LEFT_CHILD 1
#define RIGHT_CHILD 2
#define EMPTY '.'

char arr[26][3]; // node, left, right

void treeTraversal(int currentIndex, int mode)
{
    if (mode == PREORDER)
        std::cout << arr[currentIndex][CURRENT_NODE];
    if (arr[currentIndex][LEFT_CHILD] != EMPTY)
        treeTraversal(arr[currentIndex][LEFT_CHILD] - 'A', mode);
    if (mode == INORDER)
        std::cout << arr[currentIndex][CURRENT_NODE];
    if (arr[currentIndex][RIGHT_CHILD] != EMPTY)
        treeTraversal(arr[currentIndex][RIGHT_CHILD] - 'A', mode);
    if (mode == POSTORDER)
        std::cout << arr[currentIndex][CURRENT_NODE];
}

int main()
{
    int N;
    char node, leftChild, rightChild;

    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> node >> leftChild >> rightChild;
        int tmp = node - 'A';

        arr[tmp][CURRENT_NODE] = node;
        arr[tmp][LEFT_CHILD] = leftChild;
        arr[tmp][RIGHT_CHILD] = rightChild;
    }

    treeTraversal(0, PREORDER);
    std::cout << "\n";
    treeTraversal(0, INORDER);
    std::cout << "\n";
    treeTraversal(0, POSTORDER);

    return 0;
}