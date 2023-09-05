#include <iostream>
#include <map>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::map<std::string, std::string> passwordList;

    std::cin >> N >> M;
    std::string site, password;
    for (int i = 1; i <= N; i++) {
        std::cin >> site >> password;
        passwordList.insert(std::make_pair(site, password));
    }

    for (int i = 0; i < M; i++) {
        std::cin >> site;
        std::cout << passwordList[site] << "\n";
    }
    return 0;
}