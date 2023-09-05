#include <iostream>
#include <queue>
#include <algorithm>

void updateminQueue(bool isErased[], std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > &minQueue)
{
    while (!minQueue.empty() && isErased[minQueue.top().second]) {
        minQueue.pop();
    }
}

void updatemaxQueue(bool isErased[], std::priority_queue<std::pair<int, int> > &maxQueue) {
    while (!maxQueue.empty() && isErased[maxQueue.top().second]) {
        maxQueue.pop();
    }
}

int main() {
    int T, l;
    int num;
    char oper;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > minQueue;
    std::priority_queue<std::pair<int, int>> maxQueue;
    bool isErased[1000001];
    
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        std::cin >> l;

        for (int i = 0; i <= 1000000; i++) {
            isErased[i] = false;
        }

        for (int j = 0; j < l; j++) {
            std::cin >> oper >> num;

            if (oper == 'I') {
                minQueue.push(std::make_pair(num, j));
                maxQueue.push(std::make_pair(num, j));
            } else { //delete
                if (num > 0) {
                    updatemaxQueue(isErased, maxQueue);
                    if (!maxQueue.empty()) {
                        isErased[maxQueue.top().second] = true;
                        maxQueue.pop();
                    }
                } else {
                    updateminQueue(isErased, minQueue);
                    if (!minQueue.empty()) {
                        isErased[minQueue.top().second] = true;
                        minQueue.pop();
                    }
                }
            }
            //안쪽에 넣냐 빼냐 차이?
            updateminQueue(isErased, minQueue);
            updatemaxQueue(isErased, maxQueue);
        }

        if (maxQueue.empty())
            std::cout << "EMPTY\n";
        else
            std::cout << maxQueue.top().first << " " << minQueue.top().first << '\n';

        while (!minQueue.empty()) minQueue.pop();
        while (!maxQueue.empty()) maxQueue.pop();
    }
    return 0;
}