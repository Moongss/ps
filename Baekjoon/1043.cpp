#include <iostream>
#include <vector>

int parents[51];
std::vector<int> truth;
std::vector<int> party[50];

int findParent(int x) {
    if (x == parents[x])
        return x;
    return parents[x] = findParent(parents[x]);
}

void Union(int a, int b) {
    int aParent = findParent(a);
    int bParent = findParent(b);
    parents[bParent] = aParent; //ÀÌ°É parents[b] = ~·Î ÇØ¹ö·È´Ù. ¿ÏÀü ³ëµå ²÷¾î¸ÔÀº¼À.
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int N, M;
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parents[i] = i;
    }

    int truthNum, member;
    std::cin >> truthNum;
    for (int i = 0; i < truthNum; i++) {
        std::cin >> member;
        truth.push_back(member);
    }

    for (int i = 0; i < M; i++) {
        int partyTotalMember;
        int member;

        std::cin >> partyTotalMember;
        for (int j = 0; j < partyTotalMember; j++) {
            std::cin >> member;
            party[i].push_back(member);

            if (j >= 1)
                Union(party[i][j - 1], party[i][j]);
        }
    }

    int result = 0;
    for (int i = 0; i < M; i++) {
        bool isPossibleLie = true;

        for (int j = 0; j < party[i].size(); j++) {
            member = party[i][j];
            for (int k = 0; k < truth.size(); k++) {
                if (findParent(member) == findParent(truth[k]))
                    isPossibleLie = false;
            }
        }

        if (isPossibleLie)
            result++;
    }

    std::cout << result << "\n";
    return 0;
}