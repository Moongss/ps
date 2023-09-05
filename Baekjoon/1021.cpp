#include <iostream>
#include <deque>

int N, M;
std::deque<int> dq;

int main() {

    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    int moveCnt = 0;
    while (M) {
        int target;
        int targetIdx;
        int tmp;
        std::cin >> target;

        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] == target) {
                targetIdx = i;
                break;
            }
        }

        tmp = 0;
        if (targetIdx > dq.size() / 2) { // �ڷ� �ѱ�� ī��Ʈ�� �ϳ� �� �����Ѵ�...
            while (true) {
                if (target == dq.front())
                    break;
                dq.push_front(dq.back());
                dq.pop_back();
                moveCnt++;
                tmp++;
            }
        }
        else {
            while (true) {
                if (target == dq.front())
                    break;
                dq.push_back(dq.front());
                dq.pop_front();
                moveCnt++;
                tmp++;
            }
        }
        dq.pop_front();
        M--;
    }
    std::cout << moveCnt << std::endl;
    return 0;
}