#include <iostream>
#include <map>
#include <algorithm>

std::map<long, long> m;
long N, P, Q;

long S(long i) {
    std::map<long, long>::iterator iter = m.find(i);
    if (iter != m.end())
        return iter->second;
    else {
        return m.insert(std::make_pair(i, S(i / P) + S(i / Q))).first->second; // return을 잘하자
    }
}

int main() {
    std::cin >> N >> P >> Q;

    m.clear();
    m.insert(std::make_pair(0, 1));
    S(N);
    for (std::map<long, long>::iterator iter = m.begin(); iter != m.end(); iter++) {
        std::cout << iter->first << " " << iter->second << "\n";
    }
    std::cout << m.find(N)->second << std::endl;
    return 0;
}