#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;

    std::vector<std::string> pokemonNameList;
    std::map<std::string, int> pokedex;

    std::cin >> N >> M;
    std::string input;
    for (int i = 1; i <= N; i++) {
        std::cin >> input;
        pokedex.insert(std::make_pair(input, i));
        pokemonNameList.push_back(input);
    }

    for (int i = 0; i < M; i++) {
        std::cin >> input;
        if (input[0] >= '0' && input[0] <= '9')
            std::cout << pokemonNameList[std::stoi(input) - 1] << "\n";
        else
            std::cout << pokedex[input] << "\n";
    }
    return 0;
}