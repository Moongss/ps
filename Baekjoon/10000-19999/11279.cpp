#include <iostream>

int heap[100001];
int heapSize = 0;

void swap(int &a, int &b) {
    int tmp;
    
    tmp = a;
    a = b;
    b = tmp;
}

void insertMaxHeap(int data) {
    int i;

    heap[++heapSize] = data;
    for (i = heapSize; i > 1;) {
        if (heap[i] > heap[i / 2])
            swap(heap[i], heap[i / 2]);
        i /= 2;
    }
}

void removeMaxHeap() {
    if (heapSize == 0) {
        std::cout << 0 << "\n";
        return;
    }

    int toPrintData = heap[1];
    heap[1] = heap[heapSize];
    heap[heapSize--] = 0;

    for (int i = 1; i * 2 <= heapSize;) {
        if (heap[i] > heap[i * 2] && heap[i] > heap[i * 2 + 1])
            break;
        
        if (heap[i * 2] > heap[i * 2 + 1]) {
            swap(heap[i], heap[i * 2]);
            i = i * 2;
        }
        else {
            swap(heap[i], heap[i * 2 + 1]);
            i = i * 2 + 1;
        }
    }

    std::cout << toPrintData << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N;
    int data;

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> data;
        if (data == 0)
            removeMaxHeap();
        else
            insertMaxHeap(data);
    }

    return 0;
}