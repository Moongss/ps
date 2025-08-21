#include <iostream>
#include <string>

int max(int a, int b) {
    return (a > b ? a : b);
}

int main(void) {
    int lcs[1001][1001] = {0};
    std::string source;
    std::string dest;

    std::cin >> source >> dest;
 
    //add padding -> 관용이라 한다.
    source = '0' + source;
    dest = '0' + dest;

    for (size_t i = 1; i < source.length(); i++) {
        for (size_t j = 1; j < dest.length(); j++) {
            if (source[i] == dest[j]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                // lcs[i][j] = lcs[i][j - 1];
            }
        }
    }

    // for (size_t i = 0; i < source.length(); i++) {
    //     for (size_t j = 0; j < dest.length(); j++) {
    //         std::cout << lcs[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }
    std::cout << lcs[source.length() - 1][dest.length() - 1];
    return 0;
}