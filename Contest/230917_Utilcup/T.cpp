#include <iostream>
#include <string>

long N, M, T;
std::string num;
std::string rank[1002];
long tier[1002][5];

long getFixedRank(long K) {
    return std::min(M, K);
}

long getRelativeRank(long K) {
    return (M * K) / 100;
}

void setTierList(long L, long rankIdx) {
    long tierMax = (L % 4 != 0) ? L / 4 + 1 : L / 4;

    // std::cout << "tierMax : " << tierMax << std::endl;
    // std::cout << "L : " << L << std::endl;
    if (rankIdx == 0)
        tier[0][0] = tier[0][1] = tier[0][2] = tier[0][3] = tier[0][4] = 0;
    else {
        for (int i = 0; i <= 4; i++) {
            tier[rankIdx][0] += tier[rankIdx - 1][i];
        }
    }

    for (int i = 1; i <= 4; i++) {
        tier[rankIdx][i] = std::min(tierMax, L);
        L -= tier[rankIdx][i];
    }
}

int main() {
    std::cin >> N >> T;

    M = N;
    for (int rankIdx = 0; rankIdx < T; rankIdx++) {
        std::cin >> rank[rankIdx];
        std::cin >> num;

        // std::cout << "rank[i] : |" << rank[rankIdx] << "|" << std::endl;
        // std::cout << "num[i] : |" << num << "|" << std::endl;
        long rankUserNum = 0;
        if (num[num.length() - 1] == '%') { // relative
            rankUserNum = getRelativeRank(std::atoi(num.c_str()));
        } else {
            rankUserNum = getFixedRank(std::atoi(num.c_str()));
        }
        // std::cout << "M : " << M << std::endl;
        // std::cout << "rank User : " << rankUserNum << std::endl;
        setTierList(rankUserNum, rankIdx);

        // std::cout << "rank User : " << rankUserNum << std::endl;
        // for (int i = 0; i <= 4; i++) {
        //     std::cout << "tier[i] : " << tier[rankIdx][i] << std::endl;
        // }
        M -= rankUserNum;
        // std::cout << "remain M : " << M << std::endl;
    }

    if (M != 0) {
        std::cout << "Invalid System" << std::endl;
        return 0;
    }

    std::string friendRank;
    std::string targetRank;
    int targetTier = 0;
    std::cin >> friendRank;

    if (friendRank.length() > 0 && 
        friendRank[friendRank.length() - 1] >= '1' && 
        friendRank[friendRank.length() - 1] <= '4') {
        targetRank = friendRank.substr(0, friendRank.length() - 1);
        targetTier = friendRank[friendRank.length() - 1] - '0';
    } else {
        targetRank = friendRank;
    }

    // std::cout << "friendRank : " << targetRank << std::endl;
    // std::cout << "friendTier : " << targetTier << std::endl;
    bool flag = false;
    if (targetTier == 0) {
        for (int rankIdx = 0; rankIdx < T; rankIdx++) {
            if (rank[rankIdx].compare(targetRank) == 0) {
                flag = true;
                if (tier[rankIdx][1] == 0) {
                    std::cout << "Liar" << std::endl;
                    break;
                }
                
                if (rankIdx + 1 < T) {
                    std::cout << tier[rankIdx][0] + 1 << " " << tier[rankIdx + 1][0] << std::endl;
                } else {
                    std::cout << tier[rankIdx][0] + 1 << " " << N << std::endl;
                }
                break;
            }
        }
    } else {
        int result = 0;
        for (int rankIdx = 0; rankIdx < T; rankIdx++) {
            if (rank[rankIdx].compare(targetRank) == 0) {
                flag = true;
                if (tier[rankIdx][targetTier] == 0) {
                    std::cout << "Liar" << std::endl;
                    break;
                }

                for (int i = 0; i < targetTier; i++) {
                    result += tier[rankIdx][i];
                }
                std::cout << result + 1 << " " << result + tier[rankIdx][targetTier] << std::endl;
            }
        }
    }
    if (flag == false) {
        std::cout << "Liar" << std::endl;
    }
    return 0;
}